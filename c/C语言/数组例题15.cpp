#include<stdio.h>
#include<string.h>
int main(){
	int k;
	char s1[5],s2[]="yes";
	gets(s1);
	if(strcmp(s1,s2)!=0){
		printf("st1!=st2\n");
	}
	else{
		printf("st1=st2\n");
	}
	return 0;
} 
