#include<stdio.h>

int main(){
	int x,p[200001];
	int sum=0,max=0;
	
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		scanf("%d",&p[i]);
	}
	
	max=p[0];
	for(int i=0;i<x;i++){
		sum=0;
		for(int j=i;j<x;j++){
			sum=sum+p[j];
			if(max<sum){
				max=sum;
			}
		}
	}
	
	printf("%d",max);
	
	return 0;
}
