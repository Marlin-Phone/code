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
const int N = 100 + 10;

int h, w;
char g[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        // dbg(a);
        // dbg(b);
        if (a < 1 || b < 1 || a > h || b > w) {
            continue;
        }
        if (g[a][b] == '#') {
            cnt++;
            // dbg(a);
            // dbg(b);
            // cout << endl;
        }
    }
    if (cnt == 2 || cnt == 4) {
        // cout << "here" << endl;
        return true;
    } else {
        return false;
    }
}
void solve() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> g[i][j];
        }
    }
    // for (int i = 1; i <= h; i++) {
    //     for (int j = 1; j <= w; j++) {
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (g[i][j] == '#') {
                // cout << "Here" << endl;
                if (check(i, j)) {
                    continue;
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
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