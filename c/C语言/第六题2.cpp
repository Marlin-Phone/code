#include<stdio.h>
int main()
{
	printf("超市计费系统2023版1.1\n");
	printf("作者：马凌峰\n");
	int n1,n2,n3;
	float a,b,c;
	printf("请输入第一件商品的数量：");
	scanf("%d",&n1);
	printf("\n请输入第一件商品的价格：");
	scanf("%f",&a);
	printf("\n请输入第二件商品的数量：");
	scanf("%d",&n2);
	printf("\n请输入第二件商品的价格：");
	scanf("%f",&b);
	printf("\n请输入第三件商品的数量：");
	scanf("%d",&n3);
	printf("\n请输入第三件商品的价格：");
	scanf("%f",&c);
	int num=n1+n2+n3;
	float money=n1*a+n2*b+n3*c;
	if(num==1){
		money=money;
	}
	else{
		if(num==2){
			money=0.95*money;
		}
		else{
			if(num<=5&&num>=3){
				money=0.9*money;
			}
			else{
				if(num>5){
					money=0.85*money;
				}
				else{
					printf("错误");
				}
			}
		}
	}
	printf("你好，你应付：%.2f元！",money);
	return 0;
}
