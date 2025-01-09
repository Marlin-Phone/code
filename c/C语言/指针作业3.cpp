#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char publisher[50];
    float price;
};

void inputBooks(struct Book *books, int numBooks);
void printBooks(struct Book *books, int numBooks);
void findAndModifyBook(struct Book *books, int numBooks, const char *title, const char *newPublisher, float newPrice);

int main() {
    const int numBooks = 5;
    struct Book books[numBooks];

    struct Book *booksPtr = books;

    inputBooks(booksPtr, numBooks);

    printf("原始图书信息：\n");
    printBooks(booksPtr, numBooks);

    findAndModifyBook(booksPtr, numBooks, "C language", "SUST", 39.6);

    printf("\n修改后的图书信息：\n");
    printBooks(booksPtr, numBooks);

    return 0;
}

void inputBooks(struct Book *books, int numBooks) {
    for (int i = 0; i < numBooks; ++i) {
        printf("请输入第%d本书的信息：\n", i + 1);
        printf("书名：");
        scanf("%s", (books + i)->title);
        printf("出版社：");
        scanf("%s", (books + i)->publisher);
        printf("价格：");
        scanf("%f", &(books + i)->price);
    }
}

void printBooks(struct Book *books, int numBooks) {
    for (int i = 0; i < numBooks; ++i) {
        printf("书名：%s\t出版社：%s\t价格：%.2f\n", (books + i)->title, (books + i)->publisher, (books + i)->price);
    }
}

void findAndModifyBook(struct Book *books, int numBooks, const char *title, const char *newPublisher, float newPrice) {
    for (int i = 0; i < numBooks; ++i) {
        if (strstr((books + i)->title, title) != NULL) {
            strcpy((books + i)->publisher, newPublisher);
            (books + i)->price = newPrice;
            printf("已找到书名包含 %s 的图书，出版社和价格已修改。\n", title);
            return;
        }
    }
    printf("未找到书名包含 %s 的图书。\n", title);
}

