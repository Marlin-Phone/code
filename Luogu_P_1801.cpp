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

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int m, n;
priority_queue<int, vector<int>, greater<>> heap;
int add[N];
int get_num[N];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> add[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> get_num[i];
    }
    for (int j = 1; j <= n; j++) {
    }
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