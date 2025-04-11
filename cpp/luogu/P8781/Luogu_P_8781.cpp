// https://luogu.com.cn/problem/P8781
// 推导公式
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e4 + 10;
int n;
int tree[N];
int maxtree[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        tree[i] = max(n - i, i - 1) * 2;
    }

    for (int i = 1; i <= n; i++) {
        cout << tree[i] << endl;
    }

    return 0;
}