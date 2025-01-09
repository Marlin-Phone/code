#include<stdio.h>

int main(){
	printf("·´×ªÊı×Ö£º");
	
	int num,a,z;
	
	scanf("%d",&num);
	
	while(num>0){
		z=num%10;
		printf("%d",z);
		a=a*10+z;
		num=num/10;
	}
	//printf("%d",a);
	
	return 0;
} 
