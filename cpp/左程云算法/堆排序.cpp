#include <bits/stdc++.h>
using namespace std;

void heap_modify(int *arr, int n, int i) {
    while (1) {
        int max = i;
        int lchil = i * 2 + 1;
        int rchil = i * 2 + 2;

        if (lchil < n && arr[max] < arr[lchil]) {
            max = lchil;
        }
        if (rchil < n && arr[max] < arr[rchil]) {
            max = rchil;
        }

        if (max == i) {
            break;
        }
        swap(arr[i], arr[max]);
        i = max;
    }
}
void heap_sort(int *arr, int n) {
    for (int i = ((n - 1) - 1) / 2; i >= 0; i--) {
        heap_modify(arr, n, i);
    }
    int size = n;
    while (size > 1) {
        swap(arr[0], arr[size - 1]);
        size--;
        heap_modify(arr, size, 0);
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(arr) / sizeof(int);

    // 测试自底向上堆排序
    heap_sort(arr, n);

    // 预期输出：1 1 2 3 4 5 6 9
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
