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

int n, m;
priority_queue<int, vector<int>, greater<int>> small;
priority_queue<int> big;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (big.empty() || num <= big.top()) {
            big.push(num);
        } else {
            small.push(num);
        }
        if (i % 2 == 0) {
            continue;
        }
        int k = i / 2 + 1;
        if (big.size() > k) {
            small.push(big.top());
            big.pop();
        }
        if (big.size() < k) {
            big.push(small.top());
            small.pop();
        }
        cout << big.top() << endl;
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