// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long
// #define MOD 1000000007

const int N = 2e5 + 10;
int T = 1;
int n, k;
int p[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= k + 1; i++) {
        cin >> p[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;

        if (i == j) {
            cout << 1 << endl;
            continue;
        }

        if (i > j) {
            swap(i, j);
        }

        int left = upper_bound(p, p + k + 1, i) - p - 1;
        int right = upper_bound(p, p + k + 1, j) - p - 1;

        if (left == right) {
            cout << 2 << endl;
            continue;
        }

        int cnt = 0;
        for (int l = 0; l < k; l++) {
            if (i <= p[l] && p[l + 1] - 1 <= j) {
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << 2 << endl;
        } else {
            cout << 2 + cnt << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}