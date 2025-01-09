#include<stdio.h>

typedef struct 
{
	int id;
	char name[20];
	int score1;
	int score2;
	int score3;
	int sum;
}stuinfo;

int main(){
	stuinfo student[5];
	int i,j; 
	FILE *fp;
	
	fp=fopen("in.txt","r");
	
	if (fp == NULL) {
        printf("打开输入文件时出错。\n");
        return 1;
    }

	for(i=0;i<5;i++){
		fscanf(fp,"%d",&student[i].id);
		fscanf(fp,"%s",student[i].name);
		fscanf(fp,"%d",&student[i].score1);
		fscanf(fp,"%d",&student[i].score2);
		fscanf(fp,"%d",&student[i].score3);
		student[i].sum=student[i].score1+student[i].score2+student[i].score3;
		}
	
	fclose(fp);
	
	for(i=1;i<5;i++){
		for(j=0;j<5-i;j++){
			if (student[j].sum < student[j + 1].sum) {
                stuinfo tempStudent = student[j];
                student[j] = student[j + 1];
                student[j + 1] = tempStudent;
            }
		}
	}
	
	fp=fopen("out.txt","w");
	
	for(i=0;i<5;i++){
		fprintf(fp,"%d %s %d %d %d %d\n",student[i].id,student[i].name,student[i].score1,student[i].score2,student[i].score3,student[i].sum);
	}
	
	fclose(fp);
	
	return 0; 
}
