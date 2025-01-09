#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_STRING_LENGTH 100

struct Book {
    char title[MAX_STRING_LENGTH];
    char author[MAX_STRING_LENGTH];
    float price;
};

void readBooksFromFile(struct Book books[]) {
    FILE *file = fopen("books.txt", "r");

    if (file == NULL) {
        printf("文件打开失败。\n");
        return;
    }

    for (int i = 0; i < MAX_BOOKS; ++i) {
        fscanf(file, "%s %s %f", books[i].title, books[i].author, &books[i].price);
    }

    fclose(file);
}

void writeBooksToFile(const struct Book books[]) {
    FILE *file = fopen("books.txt", "w");

    if (file == NULL) {
        printf("文件打开失败。\n");
        return;
    }

    for (int i = 0; i < MAX_BOOKS; ++i) {
        fprintf(file, "%s %s %.2f\n", books[i].title, books[i].author, books[i].price);
    }

    fclose(file);
}

void addBook(struct Book books[], int index) {
    printf("请输入新增图书信息：\n");
    printf("书名：");
    scanf("%s", books[index].title);
    printf("作者：");
    scanf("%s", books[index].author);
    printf("定价：");
    scanf("%f", &books[index].price);
}

void modifyBook(struct Book books[], int index) {
    printf("请输入修改后的图书信息：\n");
    printf("新书名：");
    scanf("%s", books[index].title);
    printf("新作者：");
    scanf("%s", books[index].author);
    printf("新定价：");
    scanf("%f", &books[index].price);
}

int main() {
    struct Book books[MAX_BOOKS];
    int choice, index;

    readBooksFromFile(books);

    printf("1. 新增图书信息\n");
    printf("2. 修改图书信息\n");
    printf("请选择操作（1或2）：");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("请输入新增图书的索引（0-%d）：", MAX_BOOKS - 1);
            scanf("%d", &index);
            if (index >= 0 && index < MAX_BOOKS) {
                addBook(books, index);
            } else {
                printf("索引超出范围。\n");
            }
            break;
        case 2:
            printf("请输入要修改的图书的索引（0-%d）：", MAX_BOOKS - 1);
            scanf("%d", &index);
            if (index >= 0 && index < MAX_BOOKS) {
                modifyBook(books, index);
            } else {
                printf("索引超出范围。\n");
            }
            break;
        default:
            printf("无效的选择。\n");
            break;
    }

    writeBooksToFile(books);

    return 0;
}

