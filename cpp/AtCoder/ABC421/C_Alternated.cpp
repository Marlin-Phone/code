#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const double eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 收集所有 'B' 的原始位置（已按索引升序）
    vector<int> posB;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'B') {
            posB.push_back(i);
        }
    }

    // 计算模式1的代价：B在偶数位置 (0, 2, ..., 2n-2)
    ll cost1 = 0;
    for (int i = 0; i < n; i++) {
        cost1 += abs(posB[i] - 2 * i);
    }

    // 计算模式2的代价：B在奇数位置 (1, 3, ..., 2n-1)
    ll cost2 = 0;
    for (int i = 0; i < n; i++) {
        cost2 += abs(posB[i] - (2 * i + 1));
    }

    cout << min(cost1, cost2) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}