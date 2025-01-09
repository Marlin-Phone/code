#include<stdio.h>
int main()
{
	#define PI 3.141592653
	printf("任意输入圆半径r，圆柱高h：");
	double r,h;
	scanf("%lf%lf",&r,&h);
	printf(" C1=%.2f\n Sa=%.2f\n Sb=%.2f\n Va=%.2f\n Vb=%.2f",2*PI*r,PI*r*r,4*PI*r*r,4.0/3*PI*r*r*r,PI*r*r*h);
	return 0;
 } 
