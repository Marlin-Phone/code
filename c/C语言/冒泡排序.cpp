#include <stdio.h>

int main() {
    printf("请输入10个数：");
    static float num[10];
    int i;
    
    for (i = 0; i < 10; i++) {
        scanf("%f", &num[i]);
    }
    
    for (i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i; j++) {
            if (num[j] > num[j + 1]) {
                // 使用加减运算来完成交换操作
                num[j] = num[j] + num[j + 1];
                num[j + 1] = num[j] - num[j + 1];
                num[j] = num[j] - num[j + 1];
            }
        }
    }
    
    for (i = 0; i < 10; i++) {
        printf("%.2f ", num[i]);
    }
    
    return 0;
}

