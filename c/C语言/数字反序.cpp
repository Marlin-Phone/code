

#include <stdio.h>

int main()
{
    printf("请输入一个整数（0~99999）：");
    int num, a, b, c, d, e;
    scanf("%d", &num);
    
    a = num / 10000;
    b = num % 10000 / 1000;
    c = num % 1000 / 100;
    d = num % 100 / 10;
    e = num % 10;
    
    if (a != 0)
        printf("它是五位数\n");
    else if (b != 0)
        printf("它是四位数\n");
    else if (c != 0)
        printf("它是三位数\n");
    else if (d != 0)
        printf("它是两位数\n");
    else if (e != 0)
        printf("它是一位数\n");
        
    printf("%d,%d,%d,%d,%d\n", a, b, c, d, e);
    printf("反序数字为：%d%d%d%d%d\n", e, d, c, b, a);
    
    return 0;
}

