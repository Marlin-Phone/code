#include<stdio.h>

int gcd(int m,int n);
int main(){
	int m,n,r;
	
	scanf("%d%d",&m,&n);
	
	n=gcd(m,n);
	
	printf("最大公约数为：%d",n);
}

int gcd(int m,int n){
	int r,temp;
	
	if(m<n){
		temp=m;
		m=n;
		n=temp;
	}
	
	r=m%n;
	while(r!=0){
		m=n;
		n=r;
		r=m%n;
	}
	
	return n;
}
