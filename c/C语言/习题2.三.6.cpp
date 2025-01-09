#include<stdio.h>
double t(int n){
	int i;
	double t=1;	
	for(i=1;i<=n;i++){
		t=t*i;
	}
	return t;
}

double fact(int n){
	int i;
	double e=0;
	for(i=1;i<=n;i++){
		e=e+t(i);
	}
	return e;
}

int main(){
	int n;
	
	scanf("%d",&n);
	
	printf("%f",fact(n));
	
	return 0;
}
