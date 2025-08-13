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

int n, s;
int a[N];

void solve() {
    cin >> n >> s;
    int sum = 0;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 0) {
            cnt0++;
        } else if (a[i] == 1) {
            cnt1++;
        } else {
            cnt2++;
        }
    }

    if (s < sum) { // 输出原本即可 1
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    if (s == sum) { // 2
        cout << -1 << endl;
        return;
    }
    int d = s - sum;
    if (d == 1) {
        while (cnt0--) {
            cout << 0 << " ";
        }
        while (cnt2--) {
            cout << 2 << " ";
        }
        while (cnt1--) {
            cout << 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
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