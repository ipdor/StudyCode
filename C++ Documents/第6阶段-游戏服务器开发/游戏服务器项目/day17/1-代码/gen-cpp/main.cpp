#include <cstdio>
#include "calculate.h"
#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>


using namespace std;

int main()
{
	shared_ptr<apache::thrift::transport::TTransport> socket(new apache::thrift::transport::TSocket("192.168.64.148", 9090));

	shared_ptr<apache::thrift::protocol::TProtocol> protocol(new apache::thrift::protocol::TBinaryProtocol(socket));

	socket->open();

	calculateClient client(protocol);

	cout << client.plus(1, 1) << endl;

	getchar();

    return 0;
}