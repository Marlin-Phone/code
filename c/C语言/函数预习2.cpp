#include<stdio.h>

int sump(int x,int y){
	x=x*x;
	y=y*y;
	
	int s;
	
	s=x+y;
	
	return s;
}

int main(){
	printf("请输入两个数x y:");
	
	int x,y,s;
	scanf( "%d%d",&x,&y);
	s=sump(x,y);
	
	printf("x*x+y*y=%d",s);
	
	return 0;
}
