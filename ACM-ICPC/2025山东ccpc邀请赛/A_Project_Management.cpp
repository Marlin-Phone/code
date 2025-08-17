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
const int N = 2e5 + 10;

int n;
int a[N], b[N];
struct node {
    int a, b;
    int idx;
} node[N];
bool cmp(struct node &a, struct node &b) {
    if (a.a == b.a) {
        return a.b < b.b;
    }
    return a.a < b.a;
}
void solve() {
    vector<int> ans;
    cin >> n;
    vector<int> bigger(n + 10, 0);
    for (int i = 1; i <= n; i++) {
        cin >> node[i].a >> node[i].b;
        node[i].idx = i;
    }
    sort(node + 1, node + 1 + n, []() {

    });
    // for (int i = 1; i <= n; i++) {
    //     cout << node[i].a << " " << node[i].b << " " << endl;
    // }
    for (int i = n - 1; i >= 1; i--) {
        int length = n - i;
        if (node[i].a < node[i + 1].a) {
            bigger[i] = length;
        } else {
            bigger[i] = bigger[i + 1];
        }
    }

    cout << "bigger:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << bigger[i] << " ";
    }
    cout << endl;

    int diff = 0;
    for (int i = n; i >= 1; i--) {
        bigger[i] -= diff;
        if (node[i].b >= bigger[i]) {
            ans.push_back(node[i].idx);
        } else {
            diff++;
        }
    }
    cout << "bigger:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << bigger[i] << " ";
    }
    cout << endl;
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
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