#include <cstdio>
#include <hiredis/hiredis.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <hiredis/async.h>
#include <event.h>
#include <hiredis/adapters/libevent.h>

using namespace std;

void redis_sync()
{
	auto pc = redisConnect("127.0.0.1", 6379);
	if (NULL != pc)
	{
		freeReplyObject(redisCommand(pc, "subscribe 1"));
		//����redis����������
		redisReply *reply = NULL;
		redisGetReply(pc, (void **)&reply);

		cout << "message from channel:" << string(reply->element[1]->str) << endl;
		cout << "message content is:" << string(reply->element[2]->str) << endl;


		redisFree(pc);
	}
}

void my_callback(redisAsyncContext *c, void *preply, void *privdata)
{
	redisReply *reply = (redisReply *)preply;
	if ("message" == string(reply->element[0]->str))
	{
		cout << "message from channel:" << string(reply->element[1]->str) << endl;
		cout << "message content is:" << string(reply->element[2]->str) << endl;
	}
}

void redis_async()
{
	//1. ����libeventʵ��
	auto base = event_base_new();
	//2. �����첽����
	auto pc = redisAsyncConnect("127.0.0.1", 6379);
	//3. ����libeventʵ�����첽����
	redisLibeventAttach(pc, base);
	//4. �첽����Ϣ(ָ���ظ�������)
	redisAsyncCommand(pc, my_callback , NULL, "subscribe 1");
	//5. ��ʼ�¼�ѭ��
	event_base_dispatch(base);
}

int main()
{
	redis_async();

	getchar();
    return 0;
}