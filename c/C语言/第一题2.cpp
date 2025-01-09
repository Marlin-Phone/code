#include<stdio.h>
int main()
{
	float a,b;
	char ch;
	printf("请输入任意两个数:\n");
	scanf("%f%f",&a,&b);
	printf("请输入他们之间的运算符号:\n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case '+': printf("a+b=%.2f",a+b); break;
		case '-': printf("a-b=%.2f",a-b); break;
		case '*': printf("a*b=%.2f",a*b); break;
		case '/': 
		{
			if(b!=0)
			{
				printf("a/b=%.2f",a/b); 
			} 
			else printf("输入错误，请重新输入。") ; 
		} break;
		default: printf("输入错误，请从新输入。");
	}
	return 0;
 } 
