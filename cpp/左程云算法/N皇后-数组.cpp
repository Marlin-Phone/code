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
const int N = 100;

int n;       // 皇后数量
int path[N]; // 第i行的皇后摆在了那一列

// 检查0~i-1行皇后是否与(i, j)皇后冲突
bool check(int i, int j) { // i, j为当前行和列
    // 枚举前i行
    for (int k = 0; k < i; k++) { // k 为之前皇后的编号
        // 检查第k行皇后与当前(i, j)皇后是否冲突
        if (j == path[k] || abs(j - path[k]) == abs(i - k)) {
            return false;
        }
    }
    return true;
}

int f1(int i, int n) { // i: 当前来到的行 0-base
    // 递归结束条件
    if (i == n) {
        return 1;
    }
    int ans = 0; // 统计解的个数
    // 枚举列
    for (int j = 0; j < n; j++) {
        // 检查是否有冲突的皇后
        if (check(i, j)) {
            path[i] = j;
            ans += f1(i + 1, n);
        }
    }
    return ans;
}

int totalNqueens(int n) { return f1(0, n); }

void solve() {
    cin >> n;
    cout << totalNqueens(n) << endl;
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