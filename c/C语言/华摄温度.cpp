#include <stdio.h>
int main()
{
	printf("请输入华氏温度：");
	int c;
	scanf("%d",&c);
	double h;
	h=5.0*(c-32)/9;
	printf("摄氏温度是：%.1f",h);
	return 0;
 } 
