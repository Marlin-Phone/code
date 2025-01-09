#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("in.txt", "r");
    int i, j;
    float num[10], temp;

    for (i = 0; i < 10; i++) {
        fscanf(fp, "%f", &num[i]);
    }

    fclose(fp);

    for (i = 0; i < 9; i++) {
        int min_index = i;

        for (j = i + 1; j < 10; j++) {
            if (num[j] < num[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            temp = num[i];
            num[i] = num[min_index];
            num[min_index] = temp;
        }
    }

    fp = fopen("out.txt", "w");

    for (i = 0; i < 10; i++) {
        fprintf(fp, "%.2f ", num[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("%.2f ", num[i]);
    }

    fclose(fp);

    return 0;
}

