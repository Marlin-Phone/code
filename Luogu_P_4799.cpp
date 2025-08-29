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
const int N = 45;

int n, w;
int arr[N];
vector<int> lsum;
vector<int> rsum;

void dfs(int start, int end, int sum, vector<int> &sums) {
    if (sum > w)
        return;
    if (start == end) {
        sums.push_back(sum);
        return;
    }
    dfs(start + 1, end, sum, sums);              // 不选当前元素
    dfs(start + 1, end, sum + arr[start], sums); // 选当前元素
}
void solve() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int mid = n / 2;
    dfs(0, mid, 0, lsum);
    dfs(mid, n, 0, rsum);
    sort(lsum.begin(), lsum.end());
    sort(rsum.begin(), rsum.end());
    int ans = 0;
    int r = rsum.size() - 1;
    for (int num : lsum) {
        while (r >= 0 && num + rsum[r] > w) {
            r--;
        }
        if (r >= 0) {
            ans += r + 1;
        }
    }
    cout << ans << endl;
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