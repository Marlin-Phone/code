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

    vector<pair<int, int>> req(n + 1);
    vector<vector<int>> dependents(n + 1);
    vector<int> cnt(n + 1, 0);
    vector<bool> learned(n + 1, false);

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        req[i] = {a, b};

        if (a == 0 && b == 0) {
            cnt[i] = 0;
            learned[i] = true;
            q.push(i);
        } else {
            cnt[i] = 1;
            if (a != 0)
                dependents[a].push_back(i);
            if (b != 0)
                dependents[b].push_back(i);
        }
    }

    int ans = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans++;

        for (int v : dependents[u]) {
            if (!learned[v] && cnt[v] > 0) {
                cnt[v]--;
                if (cnt[v] == 0) {
                    learned[v] = true;
                    q.push(v);
                }
            }
        }
    }

    cout << ans << endl;
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