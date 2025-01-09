#include<stdio.h>
int main()
{
	printf("请输入三个小写字母：");
	char a,b,c;
	scanf(" %c %c %c",&a,&b,&c);
	a=a-32;
	b=b-32;
	c=c-32;
	printf("对应的大写字母为：%c %c %c",a,b,c);
	return 0;
 } 
