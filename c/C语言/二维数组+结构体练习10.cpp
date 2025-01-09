#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    Candidate candidates[3];
    candidates[0].votes = candidates[1].votes = candidates[2].votes = 0;
    strcpy(candidates[0].name, "Lisi");
    strcpy(candidates[1].name, "Zhangsan");
    strcpy(candidates[2].name, "Wuting");

    FILE *fp_in, *fp_out;
    char name[20];

    fp_in = fopen("in.txt", "r");
    if (fp_in == NULL) {
        printf("打开输入文件时出错。\n");
        return 1;
    }

    while (fscanf(fp_in, "%s", name) != EOF) {
        for (int i = 0; i < 3; i++) {
            if (strcmp(name, candidates[i].name) == 0) {
                candidates[i].votes++;
                break;
            }
        }
    }

    fclose(fp_in);

    fp_out = fopen("out.txt", "w");
    if (fp_out == NULL) {
        printf("打开输出文件时出错。\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        fprintf(fp_out, "%s %d\n", candidates[i].name, candidates[i].votes);
    }

    fclose(fp_out);

    return 0;
}

