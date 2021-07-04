#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	char ch = 0;
	//scanf("%c",&ch);
	ch = getchar();
	printf("%c\n",ch);
	getchar();
	ch = getchar();
	printf("%c\n", ch);

	system("pause");
	return 0;
}


int main18()
{
	//m.n   m指的是宽度  n指的是小数点的位数 
	double a = 3.1415;

	printf("%10.4lf\n",a);
	int  b = 10;
	printf("%d\n", b);
	printf("%5d\n", b);
	//printf("%0-5d\n", b); 左对齐和补0不能同时用
	printf("%05d\n", b);
	system("pause");
	return 0;
}


int main17()
{
	double a = 1345.21;
	printf("%lf\n",a);
	printf("%e\n", a);

	system("pause");
	return 0;
}


int main16()
{
	char ch = 'a';
	printf("%c\n",ch);
	putchar(ch);


	system("pause");
	return 0;
}


int main15()
{
	//打印时,默认输出6位小数点
	//float类型能够保证的精度是7位有效数字
	//double  类型能够保证的精度是15位有效数字
	float a = 3.1415926456;
	double b = 3.1415926456;
	printf("a=%.8f\n",a);
	printf("a=%.8lf\n", b);

	system("pause");
	return 0;
}
