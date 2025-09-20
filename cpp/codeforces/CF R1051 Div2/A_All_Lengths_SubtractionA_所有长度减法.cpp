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

void solve() {
    cin >> n;
    int maxnum = -1;
    int maxidx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (maxnum < arr[i]) {
            maxnum = arr[i];
            maxidx = i;
        }
    }
    int l = maxidx - 1, r = maxidx + 1;
    int cur = maxnum;
    while (l >= 1 && r <= n) {
        if (arr[l] == maxnum - 1) {
            l--;
            cur = arr[l];
            maxnum--;
        } else if (arr[r] == maxnum - 1) {
            r++;
            cur = arr[r];
            maxnum--;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    while (l >= 1) {
        if (arr[l] == maxnum - 1) {
            l--;
            cur = arr[l];
            maxnum--;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    while (r <= n) {
        if (arr[r] == maxnum - 1) {
            r++;
            cur = arr[r];
            maxnum--;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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