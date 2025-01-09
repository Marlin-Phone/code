#include<stdio.h>
#define PI 3.1415926

float vom(float r){
	float s;
	s=4.0/3*PI*r*r*r;
	return s;
} 

int main(){
	float r,s;
	printf("请输入球体的半径r:");
	scanf("%f",&r);
	
	s=vom(r);
	
	printf("球的体积为：%.2f",s);
	return 0;
}
