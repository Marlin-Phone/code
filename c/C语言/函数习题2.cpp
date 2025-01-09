#include<stdio.h>

float fun(float x){
	float f;
	if(x<0&&x!=3){
		f=x*x+x+6;
	}
	else if(0<=x&&x<10&&x!=2&&x!=3){
		f=x*x-5*x+6;
	}
	else{
		f=x*x-x-1;
	}
	return f;
}

int main(){
	float x,f;
	printf("input x=");
	scanf("%f",&x);
	f=fun(x);
	printf("x=%.2f,f(x)=%.2f\n",x,f);
	return 0;
}
