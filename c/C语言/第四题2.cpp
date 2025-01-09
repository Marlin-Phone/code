#include<stdio.h>
int main()
{
	int y,i=0;
	for(y=1000;y<=3000;y++)
	{
		if(y%4==0&&y%100!=0||y%400==0)
		{
			printf("%d ",y);
			i++;
		}
		if(i==5)
		{
			printf("\n");
			i=0;
		}
	}	
	return 0;
}

