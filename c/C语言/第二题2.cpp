#include<stdio.h>
int main()
{
	int year;
	for(year=1000;year%4==0&&year%100!=0||year%400==0;year++)
	{	
		printf("%d",year);
		for(int i=1;i<=5;i++) printf("\n");
	}
	return 0;
}
