#include<stdio.h>
int main(){
	int i,a[5];
	static int c[5];
	for(i=0;i<=5;i++){
		printf("%d  ",c[i]);
	}
	printf("\n");
	for(i=0;i<=5;i++){
		printf("%d  ",a[i]);
	} 
	printf("\n");
	return 0;
} 
