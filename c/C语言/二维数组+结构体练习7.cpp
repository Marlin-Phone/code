#include<stdio.h>

typedef struct 
{
	char name[20];
	int id;
	int score1;
	int score2;
	int score3;
	int sum;
}stuinfo;
int main(){
	stuinfo student[3];
	int i,maxnumber=0;
	int maxscore=0;
	for(i=0;i<3;i++){
		printf("请输入第%d个学生的信息\n",i+1);
		printf("姓名:") ;
		scanf("%s",&student[i].name);
		printf("学号:");
		scanf("%d",&student[i].id);
		printf("第一门成绩:");
		scanf("%d",&student[i].score1);
		printf("第二门成绩:"); 
		scanf("%d",&student[i].score2);
		printf("第三门成绩:");
		scanf("%d",&student[i].score3);
		student[i].sum=student[i].score1+student[i].score2+student[i].score3;
		printf("总分是：%d\n",student[i].sum);
		if(student[i].sum>maxscore){
			maxscore=student[i].sum;
			maxnumber=i;
		}
	}
	printf("总分最高的学生是第%d名的%s，总分为%d。\n",maxnumber+1,student[maxnumber].name,maxscore);
	return 0; 
}
