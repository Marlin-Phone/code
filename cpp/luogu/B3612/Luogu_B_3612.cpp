// https://luogu.com.cn/problem/B3612
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int n;
int a[N];
int m;
int S[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S[i] = a[i] + S[i - 1];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << S[r] - S[l] + a[l] << endl;
    }

    return 0;
}