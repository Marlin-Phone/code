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
const int N = 1e6 + 10;

int n;
vector<int> nxt;
void init(int n) {
    nxt.resize(2 * n + 2);
    for (int i = 0; i <= 2 * n + 2; i++) {
        nxt[i] = i;
    }
}
int find(int x) { return x == nxt[x] ? x : nxt[x] = find(nxt[x]); }

void solve() {
    cin >> n;
    init(n);
    vector<int> ans(2 * n + 2);
    for (int x = n; x >= 1; x--) {
        int i = find(0);
        int j = i + x;
        while (true) {
            j = find(j);

            if ((j - i) % x == 0) {
                break;
            }

            int k = (j - i) / x + 1;
            j = i + k * x;
        }

        ans[i] = x;
        ans[j] = x;

        nxt[i] = find(i + 1);
        nxt[j] = find(j + 1);
    }

    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] << " ";
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