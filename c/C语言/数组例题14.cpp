#include<stdio.h>
#include<string.h>
int main(){
	printf("请输入一段字符：");
	static char ch[100];
	gets(ch);
	int i,j;
	j=strlen(ch)-1;
	for(i=0;ch[i]==ch[j]&&i<j;i++,j--){
	}
	if(i<j){
		printf("不是回文。");
	}
	else{
		printf("是回文。");
	}
	return 0;
}
