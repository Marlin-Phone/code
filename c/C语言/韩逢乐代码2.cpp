#include"stdio.h"

int main()
{
	
	char shuzu[101];
	int i;
	scanf("%s",shuzu);
	int sum=0;
	for(i=0;shuzu[i]!='\0';i++)
	{
		sum+=shuzu[i];
	}
	printf("%d",sum%0x100);
	
	return 0; 
}
