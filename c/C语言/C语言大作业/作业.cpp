#include<stdio.h>
#include<stdlib.h>
//学生信息 
typedef struct _Student{
	int stuNum;
	char name[20];
	int score;
}Student; 
//结点信息
typedef struct _Node{
	Student student;
	struct _Node* next;
}Node;
 
int main(){
	//创建头结点
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL; 
	
	return 0;
} 
