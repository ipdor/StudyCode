#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main05()
{
	unsigned int d = 0xffffffff; //�����޷���int����d����16���Ʒ�ʽ��ֵ
	//����: ffffffff
	//����: 1000 0000 0000 0000 0000 0000 0000 0000 
	//ԭ��: 1000 0000 0000 0000 0000 0000 0000 0001
	printf("�з��ŷ�ʽ��ӡ��d = %d\n", d);//%d ��ӡʱ���俴����һ���з����� -1
	printf("�޷��ŷ�ʽ��ӡ��d = %u\n", d);//%u ��ӡʱ���俴����һ���޷�����0xffffffff



	system("pause");
	return 0;
}


int main04()
{
	char  num = 0x81;//���룺 1000 0001
	//1111 1110 _> 1111 1111 = -127
	//unsigned sum = 0x82;//���� = ���� = ԭ�� �� 1000 0010 


	//  1000 0001 =129
	printf("%d\n",num);//�з��Ŵ�ӡ  -127
	printf("%u\n", num);//�޷��Ŵ�ӡ
	//%d ���з��Ŵ�ӡ32λ��
	//%u  �޷��Ŵ�ӡ32λ
	system("pause");
	return 0;
}


int main03()
{
	int  b = 056;
	// 

	printf("a=%o\n", b);
	printf("a=%X\n", b);
	printf("a=%d\n", b);
	system("pause");
	return 0;
}


int main02()
{
	int a = 123;
	int  b = 056;
	int  c = 0xab;
	printf("a=%d\n",a);
	printf("a=%o\n", b);
	printf("a=%X\n", c);
	printf("a=%#X\n", c);
	system("pause");
	return 0;
}
