 #include <stdio.h>
#include <string.h>

char* findShortestString(char (*strings)[10], int numStrings);

int main() {
    char strings[5][10];

    printf("请输入5个字符串（每个字符串长度不超过10）：\n");
    for (int i = 0; i < 5; ++i) {
        printf("字符串 %d：", i + 1);
        scanf("%s", strings[i]);
    }

    char *shortestString = findShortestString(strings, 5);

    printf("\n最短字符串是：%s\n", shortestString);

    return 0;
}

char* findShortestString(char (*strings)[10], int numStrings) {
    char *shortest = strings[0];

    for (int i = 1; i < numStrings; ++i) {
        if (strlen(strings[i]) < strlen(shortest)) {
            shortest = strings[i];
        }
    }

    return shortest;
}

