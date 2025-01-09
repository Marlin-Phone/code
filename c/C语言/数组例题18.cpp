#include <stdio.h>
#include <string.h> 

int main() {
    char st[20], name[5][20];
    int i, j, p;
    
    printf("请输入5个人的名字：");
    
    for (i = 0; i < 5; i++) {
        gets(name[i]);
    }
    
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) { // Changed j <= 5 to j < 5
            if (strcmp(name[j], name[i]) < 0) {
                strcpy(st, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], st);
            }
        }
    }
    
    for (i = 0; i < 5; i++) {
        puts(name[i]);
    }
    
    return 0;
}

