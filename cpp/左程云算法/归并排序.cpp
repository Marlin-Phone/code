// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n;
int arr[N];
int help[N];

void merge(int l, int m, int r) {
    int i = l;
    int a = l;
    int b = m + 1;

    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
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

void mergeSort2() {
    for (int sz = 1; sz < n; sz *= 2) {
        for (int left = 1; left <= n - sz; left += sz * 2) {
            int m = left + sz - 1;
            int right = min(left + sz * 2 - 1, n);
            merge(left, m, right);
        }
    }
}
void mergeSort(int l, int r) {
    if (l == r) {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // mergeSort(1, n);
    mergeSort2();
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}