#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <errno.h>
#include <sys/epoll.h>


int main(int argc, char *argv[])
{
	//1.创建socket
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if (lfd == -1)
	{
		perror("socket\n");
		return 1;
	}

	//2.bind,端口复用
	int on = 1;
	int ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT,(void*)&on,sizeof(on));
	if (ret == -1)
	{
		perror("setsockopt\n");
		return 1;
	}

	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	//inet_pton(AF_INET,"192.168.138.129",(void*)&seraddr.sin_addr.s_addr);
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);  //
	seraddr.sin_port = htons(8888);
	ret = bind(lfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	if (ret == -1)
	{
		perror("bind\n");
		return 1;
	}

	//3.listen
	ret = listen(lfd, 128);
	if (ret == -1)
	{
		perror("listen\n");
		return 1;
	}

	//4.epoll init
	int epfd = epoll_create(1);
	if (epfd == -1) {
		perror("epoll_create\n");
		return 1;
	}
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = lfd;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD,lfd,&ev);//加入初始fd:lfd
	if (ret == -1)
	{
		perror("epoll_ctl(add lfd)\n");
		return 1;
	}

	//5.epoll_wait，accept
	const int MAXSIZE = 100;
	while (true)
	{
		struct epoll_event evs[MAXSIZE];
		int n = epoll_wait(epfd, evs, MAXSIZE, -1);
		if (n == -1)
		{
			perror("epoll_ctl(add cfd) \n");
			return 1;
		}

		for (int i = 0; i < n; i++)
		{
			int fd = evs[i].data.fd;
			//如果lfd改变，有新的客户端连接
			if (fd== lfd)
			{
				struct sockaddr_in cliaddr;
				int len = sizeof(cliaddr);
				int cfd = accept(lfd,(struct sockaddr*)&cliaddr,(socklen_t *)&len);//可以用accept4同时设置非阻塞
				if (cfd == -1)
				{
					continue;
				}
				char ip[16];
				cout << "New client connected. Ip:" << inet_ntop(seraddr.sin_addr.s_addr, ip, 16) << ", Port:" <<
					ntohs(seraddr.sin_port) << endl;

				struct epoll_event ev; 
				ev.events = EPOLLIN;
				ev.data.fd = cfd;
				ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);//加入初始fd:lfd
				if (ret == -1)
				{
					perror("epoll_ctl(add cfd) \n");
					continue;
				}
			}
			//如果lfd改变，可读
			else if(evs[i].events & EPOLLIN)
			{
				const int MAXBUFSIZE = 1500;
				char buf[MAXBUFSIZE];
				ret = read(fd, buf, MAXBUFSIZE);
				if (ret == -1) {
					printf("Error occured.\n");
					epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);//关闭无效fd
					close(fd);
				 }
				else if (ret == 0)
				{
					printf("Client closed.\n");
					epoll_ctl(epfd, EPOLL_CTL_DEL, fd,NULL);//关闭无效fd
					close(fd);
				}
				else {
					write(1, buf, ret);
					ret = write(fd, buf, ret);
					//if (ret == -1) {
					//	printf("Error occured.\n");
					//	epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);//关闭无效fd
					//	close(fd);
					//	continue;
					//}
					//else if (ret == 0)
					//{
					//	printf("Client closed.\n");
					//	epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);//关闭无效fd
					//	close(fd);
					//	continue;
					//}
				}
			}
		}

	}

	close(lfd);

    return 0;
}