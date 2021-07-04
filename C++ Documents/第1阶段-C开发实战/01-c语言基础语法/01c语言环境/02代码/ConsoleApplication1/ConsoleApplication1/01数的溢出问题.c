#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main01()
{
	//赋值时（输入），赋的是十进制，给的是原码。如果赋值给的是八进制或者十六进制给的是补码
	//打印时（输出），十进制打印要的是原码，如果是十六进制或八进制打印要的数补码
	//char  num = 129;
	int num = 0x80000001;
	//129的原码=反码=补码 = 1000 0001
	//但是num是有符号数，最高位为1，计算机认为这是一个负数的补码
	// 补码如何求原码？
	//补码  1000 0001
	//反码：1111 1110
	//原码： 1111 1111
	printf("num=%d\n",num);//-127


	system("pause");
	return 0;
}
