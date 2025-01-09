#include<stdio.h>
int main()
{
	int y=1000;
	do
		{
			if((y%400==0)||(y%4==0&&y%100!=0)) printf("%4d ",y);
			y++;
		}
	while(y<=2000);
	return 0;
 } 
