#include<stdio.h>

int fibo(int n){
	int temp1,temp2;
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	temp1=fibo(n-1);
	temp2=fibo(n-2);
	return temp1+temp2;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fibo(n));
	
	return 0;
}
