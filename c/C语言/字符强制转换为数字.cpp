#include<stdio.h>

int main(){
	int i,s=0;
	char ch[11];
	
	printf("请输入10位以下的数字：");
	gets(ch);
	for(i=0;i<10&&ch[i]!='\0';i++){
		int(ch[i]=ch[i]-'0');
	}
	
	for(i=0;i<10&&ch[i]!='\0';i++){
		s+=ch[i];
	}
	printf("该数字各位数之和为：%d",s);
	
	return 0;
}
