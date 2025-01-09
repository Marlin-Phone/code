#include<stdio.h>
int main()
{
	printf("请任意输入一个三位数：");
	int num,a,b,c;
	scanf("%d",&num);
	a=num/100;
	b=num%100/10;
	c=num%10;
	printf("该三位数各位数上的和为：%d",a+b+c);
	return 0;
	
 } 
