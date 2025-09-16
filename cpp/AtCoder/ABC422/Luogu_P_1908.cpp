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
int arr[N];
int help[N];

int merge(int l, int m, int r) {
    int sum = 0;
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        if (arr[a] <= arr[b]) {
            help[i++] = arr[a++];
        } else {
            sum += m - a + 1;
            help[i++] = arr[b++];
        }
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return sum;
}
int getsum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    int leftsum = getsum(l, m);
    int rightsum = getsum(m + 1, r);
    int leftrightsum = merge(l, m, r);
    // dbg(leftrightsum);
    return leftsum + rightsum + leftrightsum;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << getsum(1, n) << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << arr[i] << " ";
    // }
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