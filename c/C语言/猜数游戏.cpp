#include<stdio.h>

int main(){
	int i,num=5,num0,count;
	
	printf("猜一个在100以内的数字：");
	
	do{
		scanf("%d",&num0);
		count++;
		if(num0==num){
			printf("猜了%d次猜中了",count);
		}
		else if(num0>num){
			printf("猜大了");
		}
		else if(num0<num){
			printf("猜小了");
		} 
	}while(num0!=num);
	
	return 0;
} 
