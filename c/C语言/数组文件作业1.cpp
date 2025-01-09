#include<stdio.h>
int main(){
	float num[10];
	int i;
	float max,min;
	
	printf("请输入任意10个数：");
	for(i=0;i<10;i++){
		scanf("%f",&num[i]);
	}
	max=num[0],min=num[0];
	for(i=1;i<10;i++){
		if(num[i]<min){
			min=num[i];
		}
		if(num[i]>max){
			max=num[i];
		}
	}
	printf("min=%.2f,max=%.2f",min,max);
	return 0;
} 
