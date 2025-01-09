#include<stdio.h>

int main(){
	long long a,b;
	char ch;
	
	scanf("%d%c%d",&a,&ch,&b);
	
	if(ch=='+'){
		printf("%d",a+b);
	}
	if(ch=='-'){
		printf("%d",a-b);
	}
	if(ch=='*'){
		printf("%d",a*b);
	}
	if(ch=='/'){
		printf("%d",a/b);
	}
	
	return 0;
} 
