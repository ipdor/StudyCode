#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main14()
{
	printf("abcc\"def");



	system("pause");
	return 0;
}


//从键盘读取一个字符
int main13()
{
	char  ch = 0;
	char  num = 0;
	scanf("%c",&ch);
	printf("ch=%d\n",ch);
	scanf("%c", &ch);
	scanf("%c", &num);
	printf("num=%d\n", num);
	system("pause");
	return 0;
}



int main12()
{
	char ch = '8';//
	int a = ch - '0';
	printf("a=%d\n",a);
	char num = ' ';
	printf("%d\n",num);
	system("pause");
	return 0;
}


int main11()
{
	char ch = 'a';
	printf("%d\n",sizeof(ch));//1
	printf("%d\n", sizeof('a'));//

	system("pause");
	return 0;
}


int main10()
{
	char  ch = 'A';//ch  = 65
	ch = ch + 32;
	printf("ch=%c\n",ch);


	system("pause");
	return 0;
}


int main09()
{
	//char  ch = 'a';// ch = 97
	//printf("%d\n",ch);
	char ch = 'a';
	//printf("%d\n",'a');
	//printf("%d\n", '\n');
	printf("%c\n",ch);//打印ch值(ascii)所对应的字符


	system("pause");
	return 0;
}
