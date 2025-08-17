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

int n, k;
int cnt1, cnt2;

void solve() {
    cin >> n >> k;
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            cnt1++;
        else
            cnt2++;
    }

    // 检查k的范围
    int min_sum = n - 1;                      // 最小可能和（没有"2-2"相邻对）
    int max_sum = n - 1 + max(0ll, cnt2 - 1); // 最大可能和（所有2连在一起）

    if (k < min_sum || k > max_sum) {
        cout << -1 << endl;
        return;
    }

    // 计算需要的"2-2"相邻对数量
    int x = k - min_sum;
    // 需要将cnt2个2分成blocks个块
    int blocks = cnt2 - x;

    // 需要的分隔1的数量（不能为负数）
    int separators = max(0ll, blocks - 1);

    // 检查是否可以用1分隔这些块
    if (cnt1 < separators) {
        cout << -1 << endl;
        return;
    }

    // 构造排列
    vector<int> result;

    // 先处理剩余的1（不用于分隔的1）
    int remaining_ones = cnt1 - separators;
    for (int i = 0; i < remaining_ones; i++) {
        result.push_back(1);
    }

    // 然后交替放置2的块和1
    for (int i = 0; i < blocks; i++) {
        // 前(blocks-1)个块各含1个2，最后一个块含(x+1)个2
        int block_size = (i == blocks - 1) ? (x + 1) : 1;

        for (int j = 0; j < block_size; j++) {
            result.push_back(2);
        }

        // 如果不是最后一个块，放一个1来分隔
        if (i < blocks - 1) {
            result.push_back(1);
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
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