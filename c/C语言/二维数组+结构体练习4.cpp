#include <stdio.h>

int main() {
    int rows = 6;
    int pascal_triangle[rows][rows];

    for (int i = 0; i < rows; i++) {
        pascal_triangle[i][0] = 1;
        pascal_triangle[i][i] = 1;
    }

    for (int i = 2; i < rows; i++) {
        for (int j = 1; j < i; j++) {
            pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%4d", pascal_triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}

