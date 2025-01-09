#include<stdio.h>

int main(){
	int i,j,temp,num[10];
	
	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	}
	
	for(i=0;i<10-1;i++){
		for(j=i+1;j<10;j++){
			if(num[i]>num[j]){
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
	
	for(i=0;i<10;i++){
		printf("%d",num[i]);
	}
	
	return 0;
}
