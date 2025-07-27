// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n, m, k;

void solve() {
    cin >> n >> m >> k;
    int num = (k + n - 1) / n;
    // cout << num << endl;

    int kongwei = m - num;
    kongwei++;
    // num / m - num + 1 向上取整
    cout << (num + kongwei - 1) / kongwei << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}