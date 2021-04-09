#include "CopyFIle.h"
#include <iostream>
#include <fstream>
#include <string>

//创建读入读出文本对象
CopyFIle::CopyFIle(string inName, string outName ) {
	//打开被读入的文件
	ifstream fin(inName, ios::in|ios::binary);
	if (fin.fail())
	{
		cout << "Open inFile fail!" << endl;
		success = 0;
		throw exception("Open inFile fail!");
	}
	
	//打开被写入的文件，注意要trunc模式，防止多次写入导致和源文件不一致
	ofstream fout(outName, ios::out | ios::binary|ios::trunc);
	if (fout.fail())
	{
		cout << "Open outFile fail!" << endl;
		success = 0;
		throw exception("Open outFile fail!");
	}

	//设置缓冲区，用作读入读出的中转站
	const unsigned int BUFFERSIZE = 3096;
	char str[BUFFERSIZE];

	//当fin未结束时，持续读入，然后经过缓冲区写入fout
	while (!fin.eof())
	{
		//最大读入缓冲区中BUFFERSIZE个字符
		fin.read(str, BUFFERSIZE);
		//获取实际读出的字符数量
		unsigned int count = fin.gcount();
		//写入字符，数量为实际读出的字符数
		fout.write(str, count);
	}
	success = 1;

}
