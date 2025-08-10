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

const int N = 1e6 + 10;
// const int MOD = 1e9 + 7;
// const db eps = 1e-8;

int n, k;
int arr[N];
int st[N];
bool flag = 0;

void dfs(int x) {
    if (flag == 1) {
        return;
    }
    if (x > n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i == arr[i]) {
                cnt++;
            }
        }
        if (cnt == k) {
            flag = 1;
            for (int i = 1; i <= n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i] == 1) {
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
    cin >> n >> k;
    if (n - 1 == k) {
        cout << -1 << endl;
        return;
    }
    dfs(1);
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