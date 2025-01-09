#include<stdio.h>

int main(){
	int i,j,temp,num[10],min;
	
	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	} 
	
	for(i=0;i<9;i++){
		min=num[i];
		for(j=0;j<10;j++){
			if(num[j]<min){
				temp=min;
				min=num[j];
				num[j]=temp;
			}
		}
	}
	
	for(i=0;i<10;i++){
		printf("%d ",num[i]);
	}
	
	return 0;
}
