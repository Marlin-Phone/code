#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[10] = {9, 2, 5, 7, 1, 8, 3, 6, 10, 4};
    int i;

    printf("初始数组为：");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, 10);

    printf("\n排序后的数组为：");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

