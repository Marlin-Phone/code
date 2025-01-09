#include<stdio.h>
int main() 
{
	printf("超市计费系统2023版\n作者：马凌峰\n");
	int num;
	printf("请输入商品的数量：");
	scanf("%d",&num);
	double rmb;
	printf("请输入商品的价格：");
	scanf("%lf",&rmb);
	double z;
	printf("请输入商品打折的额度：");
	scanf("%lf",&z);
	double f;
	f=num*rmb*z;
	printf("你好，该种商品你应付：%.3lf",f); 
	return 0;
	
 } 
