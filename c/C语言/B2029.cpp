#include<stdio.h>
#include<math.h>
#define PI 3.14

int main(){
	int h,r,n;
	double s,v;
	
	scanf("%d%d",&h,&r);
	
	s=PI*r*r;
	v=s*h;
	n=ceil(20000/v);
	
	printf("%d ",n);
	
	return 0;
}
