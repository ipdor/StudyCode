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
	//��������дһ��Copy()��Ա����ר�Ÿ����ļ�,���캯��ר���������ļ���
	//�������ַ���ʵ����Copy()��������Զֻ�ܶ���0���ַ����������ˡ�
	//���������ֻ��Ϊ�˸��������ļ��Ļ�������Ҫר�Ŷ�������ifstream��Ա����
	ifstream fin;
	ofstream fout;
	bool success = 0;
};

