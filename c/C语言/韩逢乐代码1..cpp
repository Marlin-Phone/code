#include"stdio.h"

int max(int a,int b);

int main()
{
	int n,i,sum=0,a,j,c=1,goal=0,temp=0,b;
	scanf("%d",&n);
	int shuzu[n];
	int zancun[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&shuzu[i]);
	}
	for(i=0;i<n;i++)
	{
		a=shuzu[i];
		while(a)
		{
			temp=a%10;
			a=a/10;
			sum=sum+temp;
		}
		zancun[i]=sum;
		sum=0;
	}
	for(i=0;i<n;i++)
	{
		b=zancun[i];
		for(j=0;j<n;j++)
		{
			if(b<zancun[j])
			{
				c=0;	
			}
			if(j==(n-1)&&(c==1))
			{
				goal=max(goal,shuzu[i]);	
			}
			
		}
		c=1;
	}
	printf("%d",goal);
	
	printf("\nÊä³öÍê±Ï");
	
}

int max(int a,int b)
{
	int c;
	if(a==b)c=a;
	if(a>b)c=a;
	if(a<b)c=b;
	return c;
}
