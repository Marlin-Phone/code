#include<stdio.h>

int main(){
	FILE *fp;
	float scores[4][4];
	int i,j;
	
	printf("请输入3名学生的学号及每门课成绩：\n");
	printf("==================================\n");
	printf("学号    英语     大物     C语言\n");
	
	fp=fopen("学生成绩.txt","r");
	
	if (fp == NULL) {
        printf("无法打开文件\n");
        return 1;
    }
    
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			fscanf(fp,"%f",&scores[i][j]);
		}
	}
	
	fclose(fp);
	
	
	for(j=1;j<4;j++){
		for(i=0;i<3;i++){
			scores[3][j]+=scores[i][j];
		}
		scores[3][j]/=3; 
	}
	
	printf("==================================\n");
	printf("平均分:   ");
	for(j=1;j<4;j++){
		printf("%.1f\t",scores[3][j]);
	}
	 
	return 0;
} 
