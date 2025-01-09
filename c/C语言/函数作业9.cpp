#include<stdio.h>
#include<string.h>
 
void fun(char s[],char t[]){
	int i,j;
	for(i=0,j=0;i<strlen(s);i+=2,j++){
		t[j]=s[i+1];
	}
	t[j]='\0';
}
int main(){
	char s[20],t[20];
	printf("Please enter string S:");
	scanf("%s",s);
	fun(s,t);
	printf("The result is:%s\n",t);
	
	return 0;
} 
