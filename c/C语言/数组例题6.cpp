#include<stdio.h>
int main(){
	int row,col,a[3][4];
	printf("ÊäÈëÊı×Ö£º");
	for(row=0;row<3;row++){
		for(col=0;col<4;col++){
			scanf("%d",&a[row][col]);
		}
	}
	for(row=0;row<3;row++){
		for(col=0;col<4;col++){
			printf("%d ",a[row][col]);
		}
		printf("\n");
	}
	return 0;
} 
