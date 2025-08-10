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

const int N = 2e5 + 10;
// const int MOD = 1e9 + 7;
// const db eps = 1e-8;

int n, x, y;
int a[N];

void solve() {
    map<int, int> cnts;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnts[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    int x_cnt = a[n]; // 最大值

    // 得到相等的数最多的那个数和值
    int maxcnt = -1;
    int maxai = -1;
    for (auto [ai, cnt] : cnts) {
        if (cnt > maxcnt) {
            maxcnt = cnt;
            maxai = ai;
        }
    }
    for (int i = n; i >= 1; i -= cnts[x_cnt]) { //
        int y_cnt = n - maxcnt;                 // n - 个数最多的数的数量
        int x_cnt =
        // maxai =
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int y_cnt = n - maxcnt;
    if (y * y_cnt < x * x_cnt) {
        cout << y * y_cnt << endl;
    } else {
        cout << x * x_cnt << endl;
    }
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