#include<stdio.h>
int main() {
	printf("请输入你将输入数字的个数(不超过10个)：");
	int i,n;
	scanf("%d",&n);
	if (n>10||n<0){
		printf("输入错误");
		return 1;
	}
	printf("请输入%d个数字：",n);
	float a[10]; 
	for(i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
	float max=a[0],min=a[0];
	for(i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}
	}
	printf("max=%.2f,min=%.2f",max,min);
	return 0;
}
