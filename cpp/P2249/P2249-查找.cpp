// https://www.luogu.com.cn/problem/P2249
#include <iostream>
#include <vector>
using namespace std;

// 二分查找边界
int binary_search(vector<int> &num, int n, int val) {
    int i = -1, j = n;
    while (i + 1 != j) {
        int mid = (i + j) / 2;
        if (num[mid] < val)
            i = mid;
        else
            j = mid;
    }
    if (num[j] == val)
        return j + 1;
    else
        return -1;
}

int main() {
    int n, m, temp;

    cin >> n >> m;
    vector<int> num(n + 10);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        printf("%d ", binary_search(num, n, temp));
    }

    return 0;
}