#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CopyFIle
{
public :
	CopyFIle(string inName,string outName="test.mp3");
	bool isSuccess(){return  success==true;};
	~CopyFIle(){fin.close();	fout.close();}

private:
	//本来打算写一个Copy()成员函数专门复制文件,构造函数专门用来打开文件，
	//但是这种方法实际在Copy()函数中永远只能读出0个字符，最后放弃了。
	//所以这个类只是为了复制两个文件的话，不需要专门定义两个ifstream成员变量
	ifstream fin;
	ofstream fout;
	bool success = 0;
};

