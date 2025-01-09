#include<stdio.h>
int main(){
	int fibo[10]={1,1};
	int i;
	for(i=2;i<10;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	for(i=0;i<10;i++){
		printf("%d ",fibo[i]);
	}
	printf("\n");
	return 0;
}
