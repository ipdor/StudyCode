#include "CopyFIle.h"
#include <iostream>
#include <fstream>
#include <string>

//������������ı�����
CopyFIle::CopyFIle(string inName, string outName ) {
	//�򿪱�������ļ�
	ifstream fin(inName, ios::in|ios::binary);
	if (fin.fail())
	{
		cout << "Open inFile fail!" << endl;
		success = 0;
		throw exception("Open inFile fail!");
	}
	
	//�򿪱�д����ļ���ע��Ҫtruncģʽ����ֹ���д�뵼�º�Դ�ļ���һ��
	ofstream fout(outName, ios::out | ios::binary|ios::trunc);
	if (fout.fail())
	{
		cout << "Open outFile fail!" << endl;
		success = 0;
		throw exception("Open outFile fail!");
	}

	//���û����������������������תվ
	const unsigned int BUFFERSIZE = 3096;
	char str[BUFFERSIZE];

	//��finδ����ʱ���������룬Ȼ�󾭹�������д��fout
	while (!fin.eof())
	{
		//�����뻺������BUFFERSIZE���ַ�
		fin.read(str, BUFFERSIZE);
		//��ȡʵ�ʶ������ַ�����
		unsigned int count = fin.gcount();
		//д���ַ�������Ϊʵ�ʶ������ַ���
		fout.write(str, count);
	}
	success = 1;

}
