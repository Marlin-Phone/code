#include<stdio.h>

int main(){
	int num;
	
	//scanf("%d",&num);
	
	for(int j=3;j<100;j++){
		int sushu=0;
		for(int i=2;i<j;i++){
			if(j%i==0){
				sushu=1; 
			}
		}
		if(sushu==0){
			printf("%d ",j);
		}
	}
	
	return 0;
	
} 
