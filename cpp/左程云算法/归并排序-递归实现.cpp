#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int arr[N];  // 待排序数组
int help[N]; // 辅助数组

void merge(int l, int m, int r) { // 归并过程
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        if (arr[a] <= arr[b]) {
            help[i++] = arr[a++];
        } else {
            help[i++] = arr[b++];
        }
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }
}

void mergeSort1(int l, int r) { // 递归实现
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort1(l, m);
    mergeSort1(m + 1, r);
    merge(l, m, r);
}

int main() { // 主函数
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort1(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
