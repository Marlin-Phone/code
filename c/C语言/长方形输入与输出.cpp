#include <stdio.h>

int main()
{
    float length, width;
    float perimeter, area;

    printf("请输入长方形的长度：");
    scanf("%f", &length);

    printf("请输入长方形的宽度：");
    scanf("%f", &width);

    perimeter = 2 * (length + width);
    area = length * width;

    printf("长方形的周长是：%.2f\n", perimeter);
    printf("长方形的面积是：%.2f\n", area);

    return 0;
}

