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

int n;   // 皇后数量
int col; // 用整数状态(位信息)表示是否放皇后
int left;
int right;

int f2(int limit, int col, int left,
       int right) { // limit:限制为几皇后问题 col:之前皇后的列影响
                    // left:左对角线影响 right:右对角线影响
    // 递归结束条件
    if (col == limit) {
        return 1;
    }
    int ban = col | left | right;   // 禁止的列
    int candidate = limit & (~ban); // 候选列(能够放皇后的位置)
    int place = 0;                  // 放置的列
    int ans = 0;
    while (candidate) {
        place = candidate & (-candidate); // 获取当前列(提取出最右侧的1)
        candidate ^= place;
        ans +=
            f2(limit, col | place, (left | place) >> 1, (right | place) << 1);
    }
    return ans;
}

int totalNQueens(int n) {
    int limit = (1 << n) - 1;
    return f2(limit, 0, 0, 0);
}

void solve() {
    cin >> n;
    cout << totalNQueens(n) << endl;
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