#include<stdio.h>
int main()
{
	int i,a[10];
	printf("ÊäÈë10¸öÊı×Ö£º\n");
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		printf("\n");
	}
	for(i=0;i<=9;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	return 0;
}
