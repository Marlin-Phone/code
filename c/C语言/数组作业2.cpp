#include<stdio.h>
#include<string.h>

int main(){
	static char s[100];
	int i,j;
	char z;
	
	printf("ÇëÊäÈëÒ»´®×Ö·û£º");
	
	gets(s);
	j=strlen(s)-1;
	for(i=0;i<=j;i++,j--){
		z=s[i];
		s[i]=s[j];
		s[j]=z;
	}
	
	puts(s);
	
	return 0;
} 
