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

int n;
int arr[N];
int arr0[N];
int st[N];
int maxcnt = -1;
bool flag = 0;

void gcdarr(int n) {
    for (int i = n; i >= 2; i--) {
        arr0[i - 1] = __gcd(arr0[i], arr0[i - 1]);
    }
    maxcnt = max(maxcnt, arr0[1]);
    if (maxcnt == 2 && flag == 0) {
        flag = 1;
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
void dfs(int x, int n) {
    if (x > n) {
        // cout << "rescores: ";
        // for (int i = 1; i <= n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // cout << "after: ";
        for (int i = 1; i <= n; i++) {
            arr0[i] = i * arr[i];
            // cout << arr[i] << " ";
        }
        // cout << endl;

        gcdarr(n);
        // dbg(arr0[1]);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i] == 1) {
            continue;
        }
        st[i] = 1;
        arr[x] = i;
        dfs(x + 1, n);
        arr[x] = 0; // 回溯
        st[i] = 0;
    }
}
void solve() {
    // for (int n = 2; n <= 8; n++) {
    //     flag = 0;
    //     maxcnt = -1;
    //     dfs(1, n);
    //     cout << "maxcnt = " << maxcnt << endl;
    //     cout << endl;
    //     cout << endl;
    //     // for (int i = 1; i <= n; i++) {
    //     //     arr[i] *= i;
    //     // }
    //     // gcdarr(n);
    //     // dbg(arr[1]);
    // }
    cin >> n;
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
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