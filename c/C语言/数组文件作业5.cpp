#include <stdio.h>

int main() {
    char input[1000]; 
    int count = 0;
    char c;

    printf("ÇëÊäÈëÒ»´®×Ö·û´®£º\n");

    do {
        c = getchar();
        if (c != '!') {
            input[count] = c;
            count++;
        }
    } while (c != '!' && count < 999);

    input[count] = '\0';

    printf("ÄãÊäÈëµÄ×Ö·û´®ÊÇ: %s\n", input);
    printf("×Ö·û¸öÊı: %d\n", count);

    return 0;
}

