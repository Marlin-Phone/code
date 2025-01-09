#include<stdio.h>

int main(){
	int n,i,j,k,temp;
	
	int arr[10000];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	scanf("%d",&k);
	
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	if(k>n){
		printf("-1");
	}
	else if(arr[k-1]==arr[k-2]){
		printf("-1");
	}
	else if(arr[k-1]==arr[k]){
		printf("-1");
	}
	else{
		printf("%d",arr[k-1]);
	}
	
	return 0;

}
