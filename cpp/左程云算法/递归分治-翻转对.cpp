#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int n;
int arr[N];
int help[N];
int cnt = 0;

int merge(int l, int m, int r) {
    if (l >= r) {
        return 0;
    }
    int res = 0, sum = 0;
    // 统计l...r范围上,翻转对的数量,同时l...r范围统计
    for (int i = l, j = m + 1; i <= m; i++) {
        while (arr[i] > 2 * arr[j] && j <= r) {
            // sum += j - (m - 1);
            j++;
        }
        res += j - m - 1;
    }

    int i = l, a = l, b = m + 1;
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

    return res;
}
int smallSum(int l, int r) {
    if (l >= r) {
        return 0;
    }
    int m = (l + r) / 2;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << smallSum(0, n - 1);

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    return 0;
}