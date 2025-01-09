#include <stdio.h>
#include <string.h>

struct Product {
    char name[100];
    float price;
    char production_date[20];
    int stock_quantity;
    char attributes[100];
};

int main() {

    struct Product products[3];

    for (int i = 0; i < 3; i++) {
        printf("第 %d 件商品:\n", i + 1);
        printf("名称: ");
        scanf("%s", products[i].name);
        printf("单价: ");
        scanf("%f", &products[i].price);
        printf("生产日期: ");
        scanf("%s", products[i].production_date);
        printf("库存数量: ");
        scanf("%d", &products[i].stock_quantity);
        printf("商品属性: ");
        scanf("%s", products[i].attributes);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (products[j].price < products[j + 1].price) {
                struct Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    printf("\n价格由高到低排序为:\n");
    for (int i = 0; i < 3; i++) {
        printf("名称: %s\n", products[i].name);
        printf("单价: %.2f\n", products[i].price);
        printf("生产日期: %s\n", products[i].production_date);
        printf("库存数量: %d\n", products[i].stock_quantity);
        printf("商品属性: %s\n\n", products[i].attributes);
    }

    return 0;
}

