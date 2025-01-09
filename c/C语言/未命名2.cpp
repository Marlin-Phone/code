#include<stdio.h>

int main(){
	float scores[4][3]; // 修改数组大小
	int i,j;
	
	printf("请输入3名学生的学号及每门课成绩：\n");
	printf("==================================\n");
	printf("学号    英语     大物     C语言\n");
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){ // 修改循环边界
			scanf("%f",&scores[i][j]);
		}
		printf("\n");
	}
	
	for(j=0;j<3;j++){ // 修改循环边界
		for(i=0;i<3;i++){
			scores[3][j]+=scores[i][j];
		}
		scores[3][j] /= 3; // 计算平均分
	}
	
	printf("==================================\n");
	printf("平均分:   ");
	for(j=0;j<3;j++){ // 修改循环边界
		printf("%.1f    ",scores[3][j]);
	}
	 
	return 0;
}

