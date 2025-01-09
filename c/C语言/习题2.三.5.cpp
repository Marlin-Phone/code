#include<stdio.h>
#include<math.h>

int main(){
	int n,i;
	double s=0;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		s=s+sqrt(i);
	}
	
	printf("%.2f",s);
	
	return 0;
}
