#include<stdio.h>

int main(){
	int i,j;
	float num[20];
	float m;
	
	printf("请任意输入20个数：");
	for(i=0;i<20;i++){
		scanf("%f",&num[i]);
	}
	for(i=1;i<20;i++){
		for(j=0;j<20-i;j++){
			if(num[j]<num[j+1]){
				m=num[j];
				num[j]=num[j+1];
				num[j+1]=m;
			}
		}
	}
	printf("这20个数由大到小排序为：\n");
	for(i=0;i<20;i++){
		printf("%.2f ",num[i]);
	}
	return 0;
}
