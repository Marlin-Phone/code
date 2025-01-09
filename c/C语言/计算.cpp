#include<stdio.h>

int main(){
	int i;
	double n=0.0;
	
	int sign=1;
	for(i=1;i<100;i++){
		n=sign*(n+1.0/i);
		sign=-1;
	}
	
	printf("%.6f",n);
	
	return 0;
}
