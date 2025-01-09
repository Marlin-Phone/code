#include <stdio.h>

// 递归计算斐波那契数列的第n项
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("请输入斐波那契数列的项数 n：");
    scanf("%d", &n);

    if (n < 0) {
        printf("输入无效，n 应为非负整数。\n");
    } else {
        int result = fibonacci(n);
        printf("斐波那契数列的第 %d 项为 %d\n", n, result);
    }

    return 0;
}

