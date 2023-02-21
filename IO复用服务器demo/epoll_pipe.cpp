
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
	int ret = -1;
	int pfd[2];
	ret = pipe(pfd);
	if (ret ==-1 )
	{
		perror("pipe\n");
		return 1;
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork\n");
		return 1;
	}
	else if (pid == 0)  //子进程，写pipe[1]
	{
		close(pfd[0]);
		char a = 'a';
		char buf[5];
		while (true)
		{
			sleep(1);
			memset(buf, a++, 5);
			ret = write(pfd[1], buf, 5);
			if (ret == -1)
			{
				perror("cthread write\n");
				return 1;
			}
		}
		close(pfd[1]);

	}
	else//父进程，读pipe[0]
	{
		close(pfd[1]);
		int epfd = epoll_create(1);
		struct epoll_event ev;
		ev.data.fd = pfd[0];
		ev.events = EPOLLIN;
		epoll_ctl(epfd,EPOLL_CTL_ADD,pfd[0],&ev);

		while (true)
		{
			int n = epoll_wait(epfd, &ev, 1, -1);
			if (n < 0)
			{
				perror("epoll_wait\n");
				return 1;
			}
			else if (n == 1) {
				char buf[5];
				ret = read(pfd[0], buf, 5);
				if (ret == -1)
				{
					perror("write\n");
					return 1;
				}
				ret = write(1, buf, 5);
				if (ret == -1)
				{
					perror("pthread write\n");
					return 1;
				}
			}
		}
		close(pfd[0]);

	}

    return 0;
}