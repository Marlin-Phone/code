#include<stdio.h>

int f(int a,int b,int c){
	int s;
	if(b*b-4*a*c>=0){
		s=1;
	}
	else{
		s=0;
	}
	
	return s;
}

int main(){
	int a,b,c,s;
	
	scanf("%d%d%d",&a,&b,&c);
	
	s=f(a,b,c);
	if(s==1){
		printf("该函数有实根");
	}
	else{
		printf("该函数无实根");
	}
	
	return 0;
} 
