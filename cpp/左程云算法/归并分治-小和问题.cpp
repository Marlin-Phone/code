#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int arr[N];
int help[N];

int merge(int l, int m, int r) {
    // 统计部分
    int ans = 0;
    for (int i = l, j = m + 1, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }
    // 正常归并
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

    return ans;
}

int smallSum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = smallSum(0, n - 1); // 保存smallSum的返回值
    cout << result << endl;          // 输出结果

    return 0;
}
