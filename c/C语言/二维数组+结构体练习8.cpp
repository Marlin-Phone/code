#include<stdio.h>

typedef struct 
{
	char name[100];
	char chuban[100];
	int year;
	int mon;
}bookinfo;

int main(){
	bookinfo book[4];
	int i; 
	
	for(i=0;i<4;i++){
		printf("请输入第%d本书的书名、出版社、出版年份、价格：\n",i+1);
		scanf("%s%s%d%d",&book[i].name,&book[i].chuban,&book[i].year,&book[i].mon);
	}
	
	printf("出版年份大于2020的书的信息为：\n"); 
	for(i=0;i<4;i++){
		if(book[i].year>2020){
			printf("%s %s %d %d\n",book[i].name,book[i].chuban,book[i].year,book[i].mon);
		}
	}
	
	return 0;
}
