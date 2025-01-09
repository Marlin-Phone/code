#include<stdio.h>
#include<math.h>

int main(){
	int n,i,j,type=1;
	double s;
	
	scanf("%d",&n);
	
	for(i=1,j=1;i<=n;i++,j=j+2,type=-type){
		s=s+1.0*type*i/j;
	}
	
	printf("%f",s);
	
	return 0;
} 
