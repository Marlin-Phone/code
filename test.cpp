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

int n;
int a[N];
int p[N];
double dp[N];

void solve() {
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n1; i++) {
        cin >> p[i];
    }
    double res = n1;
    for (int i = 0; i < n1; i++) {
        // if (!p[i])
        // continue;                   // 成功概率=0则跳过不进行下面的计算。
        double q = 1.0 * p[i] / 100000; // 成功的概率

        // 先走i步走到 第i位置；
        // 花费1次"赌命"，看是否成功；共花费i + 1
        // 成功的期望次数为1/q次
        // 所以需要1/q-1次失败(前1/q-1次都是失败的，第1/q次成功）
        // 如：q=0.2,则1/0.2=5，即平均做5次试验就会有一次成功。（10*0.2=2,即10次试验有两次成功）
        // 每次失败，需要再多走 i-a[i]+1次，多的一次是用来"赌命"
        dp[i] = 1.0 * i + 1 + (1.0 / q - 1) * (i - a[i] + 1);
        res = min(dp[i], res);
    }
    printf("%.12lf\n", res);
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