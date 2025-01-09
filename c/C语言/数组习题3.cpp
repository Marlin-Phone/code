#include<stdio.h>
int main(){
	static int fibo[20]={1,1};
	int i,j=0;
	for(i=2;i<20;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	for(i=0;i<20;i++){
		printf("%d ",fibo[i]);
		j++;
		if(j==5){
			printf("\n");
			j=0;
		} 
	} 
	return 0;
} 
