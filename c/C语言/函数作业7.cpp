#include<stdio.h>
int average_num(int a[],int n){
	int s=0,count=0,i;
	double a_num;
	for(i=0;i<n;i++){
		s=s+a[i];
	}
	a_num=1.0*s/n;
	for(i=0;i<n;i++){
		if(a[i]<a_num){
			count++;
		}
	}
	
	return count;
}
int main(){
	int n,a[100],i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	num=average_num(a,n);
	printf("the num is:%d\n",num);
}
