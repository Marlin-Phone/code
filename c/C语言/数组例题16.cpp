#include<stdio.h>
int main(){
	printf("ÇëÊäÈë5¸öÊı£º");
	static float num[5];
	int i;
	for(i=0;i<5;i++){
		scanf("%f",&num[i]);
	}
	int j;
	float s;
	for(i=1;i<5;i++){
		for(j=0;j<5-i;j++){
			if(num[j]>num[j+1]){
				s=num[j];
				num[j]=num[j+1];
				num[j+1]=s;
			}
		}
	}
	for(i=0;i<5;i++){
		printf("%.2f  ",num[i]);
	}
	return 0;
} 
