#include<stdio.h>

int main(){
	int i,j,temp,num[10]={1,3,5,7,9,2,4,6,8,0};
	
	for(i=0;i<10-1;i++){
		for(j=0;j<10-1-i;j++){
			if(num[j]>num[j+1]){
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<10;i++){
		printf("%d",num[i]);
	}
	
	return 0;
} 
