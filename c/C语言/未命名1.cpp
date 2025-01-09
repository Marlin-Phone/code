#include<stdio.h>

int main() {
    FILE *fp;
    float scores[3][4]; // 3名学生，每门课程+学号
    int i, j;
    
    printf("请输入3名学生的学号及每门课成绩：\n");
    printf("==================================\n");
    printf("学号    英语     大物     C语言\n");
    
    fp = fopen("学生成绩.txt", "r"); // 修正文件名
    
    if (fp == NULL) {
        printf("无法打开文件\n");
        return 1;
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) { // 修正循环边界
            fscanf(fp, "%f", &scores[i][j]);
        }
    }
    
    fclose(fp);
    
    for (j = 1; j < 4; j++) { // 修改循环边界
        for (i = 0; i < 3; i++) {
            scores[3][j] += scores[i][j]; // 累加每门课程的总分
        }
        scores[3][j] /= 3.0; // 计算平均分
    }
    
    printf("==================================\n");
    printf("平均分:   ");
    for (j = 1; j < 4; j++) { // 修改循环边界
        printf("%.1f    ", scores[3][j]);
    }
    
    return 0;
}

