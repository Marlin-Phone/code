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
int p[N];

void solve() {
    string ans;
    vector<int> nums;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int flag = 1;
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (flag) {
            if (p[l] < p[r]) {
                ans.push_back('R');
                nums.push_back(p[r]);
                r--;
            } else {
                ans.push_back('L');
                nums.push_back(p[l]);
                l++;
            }
        } else {
            if (p[l] > p[r]) {
                ans.push_back('R');
                nums.push_back(p[r]);
                r--;
            } else {
                ans.push_back('L');
                nums.push_back(p[l]);
                l++;
            }
        }
        flag ^= 1;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
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