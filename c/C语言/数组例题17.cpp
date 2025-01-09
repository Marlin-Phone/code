#include<stdio.h>
int main(){
	int i,j;
	
	static int x[11][11]; 
	for(i=0;i<11;i++){
		for(j=0;j<=i;j++){
			if(j==0||i==j){
				x[i][j]=1;
				 
			}
			else{
				x[i][j]=x[i-1][j]+x[i-1][j-1];
			}
		}
	}
	for(i=0;i<11;i++){
		for(j=0;j<=i;j++){
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
