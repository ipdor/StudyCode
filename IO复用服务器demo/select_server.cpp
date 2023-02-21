#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>


int main()
{
	int ret;

	//lfd   socket
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if (lfd == -1) {
		printf("socket error.");
		return 1;
	}

	//serAddr
	struct sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(8888);
	inet_pton(AF_INET, "192.168.138.129", (void*)&serAddr.sin_addr.s_addr);

	//端口复用
	int opt = 1;
	setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));

	//bind
	ret = bind(lfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
	if (ret == -1) {
		close(lfd);
		printf("bind error.");
		return 1;
	}

	//listen
	ret = listen(lfd, 128);
	if (ret == -1) {
		close(lfd);
		printf("listen error.");
		return 1;
	}

	//select param
	fd_set originSet, rSet;
	FD_ZERO(&originSet);
	FD_ZERO(&rSet);
	FD_SET(lfd, &originSet);
	int maxfd = lfd;

	//select
	while (1) {
		rSet = originSet;
		int n = select(maxfd + 1, &rSet, NULL, NULL, NULL);
		if (n == -1) {
			close(lfd);
			printf("select error.");
			return 1;
		}
		else if (n == 0)
		{
			continue;
		}
		else//更新了fd
		{
			//如果lfd更新了
			if (FD_ISSET(lfd, &rSet)) {
				struct sockaddr_in cliAddr;
				socklen_t len = sizeof(cliAddr);
				int cfd = accept(lfd, (struct sockaddr*)&cliAddr, &len);
				if (cfd == -1)
				{
					close(lfd);
					printf("accept:");
					return 1;
				}
				char ip[16];
				printf("new client:ip%s,port %d. \n", inet_ntop(AF_INET, (void*)&cliAddr.sin_addr.s_addr, ip, 16), ntohs(cliAddr.sin_port));
				FD_SET(cfd, &originSet);
				if (cfd > maxfd)
				{
					maxfd = cfd;
				}

				if (n == 1)
				{
					continue;
				}
			}
			else { //如果cfd更新了——客户端需要响应
				for (int i = lfd + 1; i <= maxfd; i++)
				{
					if (!FD_ISSET(i, &rSet))
					{
						continue;
					}
					int cfd = i;

					//通信
					const int size = 1500;
					char buf[size] = "";
					int num = read(cfd, buf, size);
					if (num < 0)
					{
						printf("read error.\n");//遇到\n才会刷新缓冲区，如果不加，可能会没有显示
						close(cfd);
						FD_CLR(cfd, &originSet);
						continue;
					}
					else if (num == 0) {   //客户端已关闭
						printf("client closed.\n");
						close(cfd);
						FD_CLR(cfd, &originSet);
					}
					else  //成功收到
					{
						write(1, buf, num);
						write(cfd, buf, num);
					}
				}
			}
		}

	}

//缺点：退出前没有关闭所有cfd


 close(lfd);
	return 0;
}
