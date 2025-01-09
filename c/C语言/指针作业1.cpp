#include<stdio.h>
#include<string.h>

void gettype(char string[]){
	char *p,*q;
	p=string;
	q=string+strlen(string)-1;
	while(*p==*q&&p<q){
		p++;
		q--;
	} 
	if(p>=q) printf("是回文");
	else printf("不是回文");
}

int main(){
	char string[100];
	
	scanf("%s",string);
	
	gettype(string);
	
	return 0;
} 
