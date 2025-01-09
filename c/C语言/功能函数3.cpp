#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    printf("请输入第一个正整数：");
    scanf("%d", &num1);
    printf("请输入第二个正整数：");
    scanf("%d", &num2);

    int result_gcd = gcd(num1, num2);
    printf("最大公约数是：%d\n", result_gcd);

    int result_lcm = lcm(num1, num2);
    printf("最小公倍数是：%d\n", result_lcm);

    return 0;
}

