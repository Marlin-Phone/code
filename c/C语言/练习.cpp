#include <stdio.h>

int main() {
    static int score[3][4];
    int i, j, total = 0;

    printf("请输入3名学生的每门课的成绩：\n");
    
    // 读取成绩
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &score[i][j]);
        }
    }

    // 计算总分
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            total += score[i][j];
        }
    }

    // 计算平均分
    double average = total / (3.0 * 4.0); // 3 students, 4 subjects

    printf("总分：%d\n", total);
    printf("每门课程平均分：%.2lf\n", average);

    return 0;
}

