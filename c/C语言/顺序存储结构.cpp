//顺序存储结构的插入与删除 
#include<stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int ElemType;
typedef int Status; 
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList; 

SqList L;

//获得元素操作 
Status GetElem(SqList L,int i,ElemType *e){
	if(L.length  == 0 || i<1 || i>L.length){
		return ERROR;
	}
	*e=L.data[i-1];
	
	return OK;
}

//插入元素操作
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length ==MAXSIZE){
		return ERROR;
	}
	if(i<1||i>L->length + 1){
		return ERROR;
	}
	if(i<=L->length){
		for(k=L->length-1;k>=i-1;k--){
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;
	L->length++;
} 

int main(void){
	int e;
	
	printf("请输入你要插入的数字:");
	scanf("%d",&e);
	
	Status GetElem(L,e);
	
	
	
} 
