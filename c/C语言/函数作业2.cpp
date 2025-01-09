#include<stdio.h>

int sex(char IDnumber[]){
	int number;
	number=IDnumber[16]-'0';
	if(number%2==1){
		return 1;
	}
	else{
		return 0;
	}
	 
}

int main(){
	int ret;
	char IDnumber[19];
	
	scanf("%s",IDnumber);
	
	ret=sex(IDnumber);
	if(ret==1){
		printf("先生");
	}
	else{
		printf("女士");
	}
	
	return 0;		
}
