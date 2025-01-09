#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("word.txt", "r"); 
    if (file == NULL) {
        printf("无法打开文件 'word.txt'\n");
        return 1;
    }

    char c;
    int count = 0;

    while ((c = fgetc(file)) != EOF && c != '!') {
        count++;
    }

    fclose(file); 

    printf("从文件中读取的字符串字符个数: %d\n", count);

    return 0;
}

