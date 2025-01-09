#include<stdio.h>

int peach(int i){
	if(i==10){
		return 1;
	}
	else{
		return (1+peach(i+1))*2;
	}
}

int main(){
	printf("%d",peach(1));
	
	return 0;
}
