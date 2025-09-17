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
const int N = 1e6 + 10;

int m, n;
priority_queue<int, vector<int>, greater<>> a; // 小
priority_queue<int> b;                         // 大
int add_num[N];
int get_num[N];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> add_num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> get_num[i];
    }
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        while (idx <= get_num[i]) {
            // a.push(add_num[idx]);
            if (b.empty() || add_num[idx] <= b.top()) {
                b.push(add_num[idx]);
            } else {
                a.push(add_num[idx]);
            }
            idx++;
        }
        int k = i;
        while (b.size() > k) {
            a.push(b.top());
            b.pop();
        }
        while (!a.empty() && b.size() < k) {
            b.push(a.top());
            a.pop();
        }
        cout << b.top() << endl;
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