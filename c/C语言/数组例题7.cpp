#include<stdio.h>
int main(){
	static int n[2][3];
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			scanf("%d",&n[i][j]);
		}
	}
	int max=n[0][0],min=n[0][0],row,col,row2,col2;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			if(max<=n[i][j]){
				max=n[i][j];
				row=i+1;
				col=j+1;
			}
			if(min>=n[i][j]){
				min=n[i][j];
				row2=i+1;
				col2=j+1;
			}
		}
	}
	printf("max=%d row=%d col=%d\nmin=%d row=%d col=%d",max,row,col,min,row2,col2);
	return 0;
} 
