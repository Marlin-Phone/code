//通过输入精度近似计算e的值 
#include<stdio.h>

int getn1(int n){
	int i,n1=1;
	for(i=1;i<=n;i++){
		n1=n1*i;
	}
	return n1;
}
int main(){
	int i,n1;
	double e,jindu;
	
	scanf("%lf",&jindu);
	
	for(i=1;1.0/n1>=jindu;i++){
		n1=getn1(i);
		printf("%d ",n1);
		e=e+1.0/n1;
	}
	
	printf("e=%f",e);
	
	return 0;
}
