#include <iostream>
using namespace std;

int N, K;
int A[10010];

// 快速排序
int q_sort(int l, int r) {
    int i = l, j = r;
    int key = A[l];
    while (i < j) {
        while (i < j && A[j] >= key)
            j--;
        A[i] = A[j];
        while (i < j && A[i] <= key)
            i++;
        A[j] = A[i];
    }
    A[i] = key;
    return i;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    return 0;
}