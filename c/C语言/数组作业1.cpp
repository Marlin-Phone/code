#include<stdio.h>
#include<string.h>
int main(){
	printf("请任意输入一串字符：");
	static char s[100],t[100];
	char m; 
	gets(s);
	int n=strlen(s)-1;
	int i,j;
	for(i=0,j=n;i<=n&&j>=0;i++,j--){
		t[j]=s[i];
	}
	t[n+1]='\0';
	puts(t);
	return 0;
} 
