#include <stdio.h>

int main() {
    int i, j, m;
    int num[10];
    FILE *fp;

    fp = fopen("shuju.txt", "r");
    if (fp == NULL) {
        printf("无法打开输入文件\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        fscanf(fp, "%d", &num[i]);
    }
    fclose(fp);

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (num[j] < num[j + 1]) {
                m = num[j];
                num[j] = num[j + 1];
                num[j + 1] = m;
            }
        }
    }

    fp = fopen("out.txt", "w+");
    if (fp == NULL) {
        printf("无法打开输出文件\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        fprintf(fp, "%d ", num[i]);
    }

    fclose(fp);

    return 0;
}

