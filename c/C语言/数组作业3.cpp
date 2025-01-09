#include<stdio.h>
#include<string.h>

int main(){
	printf("请输入一个英文句子：");
	
	static char sen[100];
	gets(sen);
	int n=strlen(sen)-1;
	int i,word=0;
	
	for(i=0;i<=n;i++){
		if(sen[i]!=' '&&(sen[i+1]=='\t'||sen[i+1]=='\n'||sen[i+1]==' '||sen[i+1]=='\0')){
			word++;
		}
	}
	printf("单词个数为：%d",word);
	
	return 0;
} 
