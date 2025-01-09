#include<stdio.h>

float fmax(float a[],int n){
	int max=a[0];
	for(int i=1;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}	
	}
	return max;
} 
float fmin(float a[],int n){
	int min=a[0];
	for(int i=1;i<n;i++){
		if(min>a[i]){
			min=a[i];
		}	
	}
	return min;
}
float fdif(float a[],int n){
	float dif;
	dif=fmax(a,n)-fmin(a,n);
	return dif;
}

int main(){
	int n;
	float a[100]={1,2,4,5,3,77,-11.3,543.6,35.5,3,13.3,100,-22};
	scanf("%d",&n);
	printf("%f",fdif(a,n));

	return 0;
}
