// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e5 + 10;
int n, m;
int A[N];
int L, minL;

void dfs(int x, int cnt) {
    if (x > n) {
        return;
    }

    if (cnt > m) {
    }

    dfs()
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    dfs(1, 0);

    cout << minL;

    return 0;
}