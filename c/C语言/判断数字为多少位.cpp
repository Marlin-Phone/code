#include<stdio.h>

int main(){
	int n,num;
	
	scanf("%d",&num);
	
	
	while(num>0){
		num=num/10;
		n++;
	}
	
	printf("%d",n);
	
	return 0;
} 
