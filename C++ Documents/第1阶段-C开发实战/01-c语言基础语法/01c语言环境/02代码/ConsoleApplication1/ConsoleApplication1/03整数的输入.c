#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main08()
{
	short num = 10;
	printf("%hd\n",num);


	system("pause");
	return 0;
}



int main07()
{
	char a;
	short   b;
	int c;
	long   d;
	long long e;
	//sizeof 用来测数据类型的大小
	int len = sizeof(a);
	printf("%d\n",len);
	printf("%d\n",sizeof(a));
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(c));
	printf("long = %d\n", sizeof(d));
	printf("%d\n", sizeof(e));
	printf("%d\n", sizeof(int));


	system("pause");
	return 0;
}

int main06()
{
	int  num = 0;
	int sum = 0;
	//scanf("%d %d",&num,&sum);
	scanf("%d",&num);
	printf("%d\n",num);
//	printf("%d\n", sum);
	system("pause");
	return 0;
}
