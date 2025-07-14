// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 4e5 + 10;
int T = 1;
int n;
int a[N];
int L[N], R[N], l = 0, r = N;

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) { // 定义域
        cin >> a[i];
    }
    for (int i = 1; i <= 2 * n; i++) { // 定义域
        if (L[a[i]] == 0) {
            L[a[i]] = i;
            l = max(L[a[i]], l); // 最靠右的l
        } else {
            R[a[i]] = i;
            r = min(R[a[i]], r); // 最靠左的r
        }
    }
    // for (int i = 1; i <= n; i++) { // 值域
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << R[i] << " ";
    // }
    // cout << endl;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (R[i] - L[i] - 1);
    }
    // debug(sum);
    int mul = 2 * (l - r);
    // debug(l);
    // debug(r);
    // cout << mul << endl;
    if (mul < 0) {
        cout << sum;
    } else {
        sum += mul;
        cout << sum;
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