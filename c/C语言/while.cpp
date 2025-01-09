#include<stdio.h>
int main()
{
	int y=1000;
	while(y<=2000)
	{
		if((y%400==0)||(y%4==0&&y%100!=0)) printf("%4d ",y); y++;
	}	
	return 0;
}
