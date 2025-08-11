#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define db double
#define float db
#define vi vector<int>
#define pii pair<int, int>
#define pdd pair<db, db>
// Aliases
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define endl '\n'
// Iterating
#define F(i, m) for (int i = 1; i <= m; i++)
#define fi(m) F(i, m)
#define fj(m) F(j, m)
#define fk(m) F(k, m)
#define ALL(x) x.begin(), x.end()
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

const int N = 510;
// const int MOD = 1e9 + 7;
// const db eps = 1e-8;

int n, m;
int a[N][N];
vector<pair<int, int>> bad;
vector<vector<int>> v(505);

void solve() {
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == min(i, j)) {
                ans++;
            } else {
                bad.emplace_back(i, j);
                v[min(i, j)].emplace_back(a[i][j]);
            }
        }
    }

    int add = 0;
    for (auto &[x, y] : bad) {
        int current_val = a[x][y];
        int target_layer = current_val;
        for (auto val : v[target_layer]) {
            if (val == min(x, y)) {
                add = 2;
                break;
            }
        }

        for (auto &val : v[a[x][y]]) {
            add = 1;
            if (min(x, y) == val) {
                add = 2;
                break;
            }
        }
        if (add == 2) {
            break;
        }
    }

    cout << ans + add << endl;
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