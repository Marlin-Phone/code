#include<stdio.h>

int main(){
	int i,n,t;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		t=t*i;
	}
	
	printf("%d",t);
	
	return 0;
}
