#include "GameChannel.h"
#include "GameMsg.h"
#include "msg.pb.h"
#include "AOIWorld.h"
#include "ZinxTimer.h"
#include "RandomName.h"

extern RandomName random_name;

void daemonlize()
{
	//1 fork
	int ipid = fork();
	if (0 > ipid)
	{
		exit(-1);
	}
	if (0 < ipid)
	{
		//2 �������˳�
		exit(0);
	}
	
	//3 �ӽ��� ���ûػ�ID
	setsid();
	//4 �ӽ��� ����ִ��·��

	//5 �ӽ��� �ض���3���ļ�������/dev/null
	int nullfd = open("/dev/null", O_RDWR);
	if (nullfd >= 0)
	{
		dup2(nullfd, 0);
		dup2(nullfd, 1);
		dup2(nullfd, 2);
		close(nullfd);
	}

	//���̼��
	while (1)
	{
		int pid = fork();
		if (0 > pid)
		{
			exit(-1);
		}

		/*�����̵��ӽ����˳�*/
		if (0 < pid)
		{
			int iStatus = 0;
			wait(&iStatus);
			if (0 == iStatus)
			{
				exit(0);
			}
		}
		/*�ӽ�������ѭ��ִ����Ϸҵ��*/
		else
		{
			break;
		}
	}
}

int main()
{
	daemonlize();

	random_name.LoadFile();
	ZinxKernel::ZinxKernelInit();
	/*��Ӽ���ͨ��*/
	ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(8899, new GameConnFact())));
	ZinxKernel::Zinx_Add_Channel(*(new ZinxTimerChannel()));
	ZinxKernel::Zinx_Run();
	ZinxKernel::ZinxKernelFini();

	return 0;
}