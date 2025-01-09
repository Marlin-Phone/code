#include<stdio.h>
#include<string.h>
int main(){
	printf("请输入任意一串字符：");
	static char ch[100];
	int i,num=0;
	gets(ch);
	for(i=0;i<strlen(ch);i++){
		if((ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z')){
			num++;
		}
	}
	printf("其中字母个数为%d",num);
	return 0;
} 
