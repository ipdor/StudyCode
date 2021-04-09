// CopyFiile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include "CopyFIle.h"
using namespace std;

int main()
{
	CopyFIle cf("Theme wholesome edition.mp3");
	if (cf.isSuccess())
	{
		cout << "Copy file Success!" << endl;
	}
	return 0;
}
