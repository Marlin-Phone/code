#include<stdio.h>

int main(){
	int snum,i,j;
	
	scanf("%d",&i);
	for(j=2;j<i;j++){
		if(i%j!=0){
			printf("%d ",i);
			break;
		}
	}

	
	return 0;
	
} 
