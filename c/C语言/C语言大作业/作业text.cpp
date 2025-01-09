/*用链表实现学生成绩信息的管理*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STU{
	int ID;
	char name[20];
	int score;
	struct STU *next;
}STU; 

STU *Create_Stu_Doc();//新建链表 
STU *InsertDoc(STU *head,STU *stud);//插入(有问题)
STU *DeleteDoc(STU *head,int ID);//删除
void Print_Stu_Doc(STU *head);//遍历

int main(){
	STU *head,*p;
	int choice,ID,score;
	char name[20];
	int size=sizeof(STU);
	
	do{
		system("cls"); //调用DOS命令cls清屏
	    printf("====同学录管理信息系统====\n");
	    printf("\t1. 创建同学信息\n");
	    printf("\t2. 添加同学信息\n");
	    printf("\t3. 删除同学信息\n");
	    printf("\t4. 列出同学信息\n");
	    printf("\tX. XXXX所有同学\n");
	    printf("\t0. 退出系统\n");
	    printf("========================\n");
	    printf("请输入你的选择（0-4）：");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=Create_Stu_Doc();
				break;
			case 2:
				printf("请输入 学号，姓名 和 成绩：\n");
				scanf("%d%s%d",&ID,name,&score);
				p=(STU*)malloc(size);
				p->score =score;
				head=InsertDoc(head,p);
				break;
			case 3:
				printf("请输入 学号：\n");
				scanf("%d",&ID);
				head=DeleteDoc(head,ID);
				break;
			case 4:
				Print_Stu_Doc(head);
				break;
			case 0:
				printf("\n欢迎下次使用本系统，再见！");
				exit(0);
		}
	}while(1);
	
	return 0;
} 

//新建链表
STU *Create_Stu_Doc(){
	STU *head,*p;
	int ID,score;
	char name[20];
	int size=sizeof(STU);
	
	head=NULL;
	printf("请输入 学号，姓名 和 成绩：\n（输入0则退出）\n");
	scanf("%d",&ID);
	if(ID!=0){
		scanf("%s%d",name,&score);
		while(ID!=0){
			p=(STU*)malloc(size);
			p->ID =ID;
			strcpy(p->name ,name);
			p->score =score;
			head=InsertDoc(head,p);//调用插入函数
			scanf("%d%s%d",&ID,name,&score); 
		}	
	} 
	return head;
}

//插入操作
STU *InsertDoc(STU *head,STU *stud){
	STU *ptr,*ptr1,*ptr2;
	
	ptr2=head;
	ptr=stud;//*ptr指向待插入的新的学生记录结点
	//原链表为空时的插入
	if(head==NULL){
		head=ptr;
		head->next=NULL;
	} 
	else{
		while((ptr->ID >ptr2->ID )&&(ptr->next !=NULL)){
			ptr1=ptr2;
			ptr2=ptr2->next ;
		}
		if(ptr->ID <=ptr2->ID ){//在ptr1与ptr2之间插入新结点 
			if(head==ptr2) head=ptr;
			else ptr1->next =ptr;
			ptr->next =ptr2;
		}
		else{//新插入结点成为尾结点 
			ptr2->next =ptr;
			ptr->next =NULL;
		} 
	}
	return head; 
} 
//删除操作 
STU *DeleteDoc(STU *head,int ID){
	STU *ptr1,*ptr2;
	
	//要被删除结点为表头结点
	while(head!=NULL&&head->ID==ID){
		ptr2=head;
		head=head->next;
		free(ptr2);
	} 
	if(head==NULL)
		return NULL;
	//要被删除的结点为非表头结点
	ptr1=head;
	ptr2=head->next;
	while(ptr2!=NULL){
		if(ptr2->ID ==ID){
			ptr1->next =ptr2->next ;
			free(ptr2);
		}
		else
			ptr1=ptr2;
			ptr2=ptr1->next ;
	}
	return head; 
} 

//遍历操作
void Print_Stu_Doc(STU *head){
	STU *ptr;
	if(head==NULL){
		printf("\n无记录\n");
		return;
	}
	printf("\n学生们的信息为：\n");
	printf("学号\t 姓名\t 成绩\n");
	for(ptr=head;ptr!=NULL;ptr=ptr->next ){
		printf("%d\t%s\t%d\n",ptr->ID ,ptr->name ,ptr->score );
	}
}


















