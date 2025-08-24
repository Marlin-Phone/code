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
#define vii vector<pii>
#define pdd pair<db, db>
#define vdd vector<pdd>
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
#define pow2(x) ((x) * (x))
#define pdis(a, b) (sqrt(pow2(a.x - b.x) + pow2(a.y - b.y)))
// Debugging
#define dbg(x) cout << "Dbg: " << (#x) << " = " << (x) << endl

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const int linf = 1e20;
const db dinf = 1e308;
const db eps = 1e-10;

int n;
pdd points[N];

bool cmp_plus(pdd a, pdd b) { return a.x + a.y < b.x + b.y; }

bool cmp_minus(pdd a, pdd b) { return a.x - a.y < b.x - b.y; }

db calc(pdd a, pdd b) {
    db mdis = fabs(a.x - b.x) + fabs(a.y - b.y);
    db odis = pdis(a, b);
    return mdis / odis;
}

db find_max() {
    double m = -dinf;
    fi(n - 1) { m = max(calc(points[i], points[i - 1]), m); }
    m = max(calc(points[0], points[n - 1]), m);
    return m;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + n, cmp_plus);
    db result = find_max();
    sort(points, points + n, cmp_minus);
    result = max(result, find_max());

    cout << fixed << setprecision(12) << result << endl;
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