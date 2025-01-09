#include<stdio.h>
int main()
{
	int a,b;
	double s;
	printf("请输入三角形的底和高：");
	scanf("%d%d",&a,&b);
	s=a*b/2;
	printf("三角形的面积为：%.1f",s);
	return 0;
 } 
