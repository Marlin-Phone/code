#include<stdio.h>

void printfsquare(int n);
void printftriangle(int n);
int main(){
	int n;
	
	scanf("%d",&n);
	
	printfsquare(n);
	putchar('\n');
	printftriangle(n);
	
	return 0;
}
void printfsquare(int n){
	int i;
	
	for(i=1;i<=n*n;i++){
		if(i<=9){
			printf("0%d",i);
		}
		else{
			printf("%d",i);
		}
		if(i%n==0){
			putchar('\n');
		}
	}
}
void printftriangle(int n){
	int i,j=1,count=0,count0=1;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			printf("  ");
			count++;
		}
		for(j=1;j<=i;j++){
			if(count0<=9){
				printf("0%d",count0);
				count++;
				count0++;
			}
			else{
				printf("%d",count0);
				count++;
				count0++;
			}
			if(count%n==0){
				putchar('\n');
			}
		}
	}
}
 
