#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
// #define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 60;

int n;
int arr[N];
double Ecnt = 0;
int help[N];

int merge(int l, int m, int r) {
    int a = l;
    int b = m + 1;
    int idx = l;
    int res = 0;
    while (a <= m && b <= r) {
        if (arr[a] <= arr[b]) {
            help[idx++] = arr[a++];
        } else {
            res += m - a + 1;
            help[idx++] = arr[b++];
        }
    }
    while (a <= m) {
        help[idx++] = arr[a++];
    }
    while (b <= r) {
        help[idx++] = arr[b++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return res;
}

int mergeSort(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    int lnum = mergeSort(l, m);
    int rnum = mergeSort(m + 1, r);
    int lrnum = merge(l, m, r);
    return lnum + rnum + lrnum;
}

// 实际上O(n^2)的暴力求逆序对要比这里的归并排序O(nlogn)快的多。
// 因为n=51，非常小，常数占主要作用。
void solve() {
    // int cnt = 0;
    // n = 51;
    // for (int i = 1; i <= n; i++) {
    //     arr[i] = i;
    // }
    // int ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i + 1; j <= n; j++) {
    //         for (int k = 1; k <= n; k++) {
    //             for (int l = k + 1; l <= n; l++) {
    //                 swap(arr[i], arr[j]);
    //                 swap(arr[k], arr[l]);
    //                 cnt = mergeSort(1, n);
    //                 Ecnt += cnt;
    //                 ans++;
    //             }
    //         }
    //     }
    // }
    // printf("%lf", Ecnt / ans);
    cout << "65.33" << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}