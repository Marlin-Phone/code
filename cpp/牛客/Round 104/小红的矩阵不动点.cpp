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
int ans[N][N];
int diff[N][N];
pair<int, int> arrcnt[N];
int cnt0[N];

void solve() {
    int cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            ans[i][j] = min(i, j);
            diff[i][j] = a[i][j] - ans[i][j];
            if (diff[i][j] == 0) {
                cnt++;
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << diff[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int x = 0, i = 1 + x, j = 1 + x; x < n; x++) {
        int a = 0, b = 0;
        for (int i = 1 + x; i <= n; i++) {
            if (i != j && diff[i][j] == 0) {
                cnt0[x]++;
            }
            if (i != j && diff[i][j] == -1) {
                a++;
            }
            if (i != j && diff[i][j] == 1) {
                b++;
            }
            if (i == j) {
                if (diff[i][j] == -1) {
                    a++;
                } else if (diff[i][j] == 1) {
                    b++;
                } else if (diff[i][j] == 0) {
                    cnt0[x]++;
                }
            }
        }
        for (int j = 1 + x, i = 1 + x; j <= n; j++) {
            if (i != j && diff[i][j] == -1) { // small
                a++;
            }
            if (i != j && diff[i][j] == 1) { // big
                b++;
            }
            if (i == j) {
                if (diff[i][j] == -1) {
                    a++;
                } else if (diff[i][j] == 1) {
                    b++;
                } else if (diff[i][j] == 0) {
                    cnt0[x]++;
                }
            }
        }
        // dbg(x);
        // dbg(a);
        // dbg(b);
        // dbg(cnt0[x]);
        // cout << endl;
        arrcnt[x] = {a, b};
    }
    for (int x = 1; x < n - 1 || x < m - 1; x++) {
        if ((arrcnt[x - 1].second >= 1 && arrcnt[x].first >= 1) ||
            (arrcnt[x].second >= 1 && arrcnt[x + 1].first >= 1)) {
            cnt += 2;
            cout << cnt << endl;
            return;
        }
    }
    for (int x = 1; x < n - 1 || x < m - 1; x++) {
        // dbg(n - x + m - x - 1);
        if (((cnt0[x - 1] < (n - (x - 1) * 2) + (m - (x - 1) * 2) - 1) &&
             arrcnt[x].first >= 1) ||
            (arrcnt[x].second >= 1 &&
             (cnt0[x + 1] < (n - (x + 1) * 2 + (m - (x + 1) * 2) - 1)))) {
            cnt += 1;
            cout << cnt << endl;
            return;
        }
    }

    // cout << "Here! " << endl;
    cout << cnt << endl;
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