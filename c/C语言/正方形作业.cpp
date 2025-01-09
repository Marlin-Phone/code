 #include <stdio.h>

int main()
{
    double a;
    double b;
    double area;
    double length;

    a = 20.5;
    b = 14.8;

    length = 2 * (a + b);
    area = a * b;

    printf("长方形的周长是%f，面积是%f",length,area);
    
    return 0;
}


