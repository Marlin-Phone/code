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
pair<int, int> point[N];
double mindis = 1e9;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> point[i].x >> point[i].y;
        // scanf("%lf%lf", &point[i].x, &point[i].y);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x_1 = point[i].x;
            int y_1 = point[i].y;
            int x_2 = point[j].x;
            int y_2 = point[j].y;
            mindis = min(mindis, sqrt(abs((x_1 - x_2) * (x_1 - x_2)) +
                                      abs((y_1 - y_2) * (y_1 - y_2))));
        }
    }
    printf("%.4lf", mindis);
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