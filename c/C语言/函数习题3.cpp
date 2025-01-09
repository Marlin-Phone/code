#include <stdio.h>

void fun(char s[], char c) {
    int i, k = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[k] = s[i];
            k++;
        }
    }
    s[k] = '\0'; // 确保在字符串的末尾添加空字符
}

int main() {
    char str[20], ch;
    printf("请输入一串字符串：");
    gets(str);
    printf("请输入要删除的字符：");
    ch = getchar();
    fun(str, ch);
    printf("删除后的字符串为: %s\n", str);
    return 0;
}

