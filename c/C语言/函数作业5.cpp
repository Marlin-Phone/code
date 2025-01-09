#include<stdio.h>

long fun(long num){
	int i,t=1;
	while(num!=0){
		t=t*(num%10);
		num=num/10;
	} 
	return t;
}

int main(){
	long n;
	
	printf("\nPlease enter a number:");
	scanf("%ld",&n);
	
	printf("\n%ld\n",fun(n));
	
	return 0;
} 
