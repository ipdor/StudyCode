#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main05()
{
	unsigned int d = 0xffffffff; //定义无符号int变量d，以16进制方式赋值
	//补码: ffffffff
	//反码: 1000 0000 0000 0000 0000 0000 0000 0000 
	//原码: 1000 0000 0000 0000 0000 0000 0000 0001
	printf("有符号方式打印：d = %d\n", d);//%d 打印时把其看成是一个有符号数 -1
	printf("无符号方式打印：d = %u\n", d);//%u 打印时把其看出是一个无符号数0xffffffff



	system("pause");
	return 0;
}


int main04()
{
	char  num = 0x81;//补码： 1000 0001
	//1111 1110 _> 1111 1111 = -127
	//unsigned sum = 0x82;//补码 = 反码 = 原码 ： 1000 0010 


	//  1000 0001 =129
	printf("%d\n",num);//有符号打印  -127
	printf("%u\n", num);//无符号打印
	//%d 是有符号打印32位数
	//%u  无符号打印32位
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
