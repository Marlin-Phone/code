#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, m;
vector<pair<int, int>> hurt(N);
int arr[N];
int ans = 1e9;
int st[N];

void dfs(int x) {
    if (x > n) {
        int m0 = m;
        for (int i = 1; i <= n; i++) {
            if (m0 <= 0) {
                ans = min(ans, i);
                break;
            }
            int idx = arr[i];
            if (m0 <= hurt[idx].y) {
                m0 -= 2 * hurt[idx].x;
            } else {
                m0 -= hurt[idx].x;
            }
            if (m0 <= 0) {
                ans = min(ans, i);
                break;
            }
        }

        return;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i]) {
            continue;
        }
        st[i] = 1;
        arr[x] = i;
        dfs(x + 1);
        st[i] = 0;
        arr[x] = 0;
    }
}
void solve() {
    memset(st, 0, sizeof(st));
    ans = 1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> hurt[i].x >> hurt[i].y;
    }
    // dbg(n);
    dfs(1);
    cout << ((ans == 1e9) ? -1 : ans) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}