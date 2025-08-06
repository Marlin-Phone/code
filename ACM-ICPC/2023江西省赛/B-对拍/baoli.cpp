// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
int T = 1;
int n, m, x;
int k;
int a[N];
int b[N];
int S[N];
int b_t[N];
int cnt[N];

void solve() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < k; i++) {
        S[i] = S[i - 1] + a[i];
    }
    cin >> n >> m >> x;
    // int bn = (n / k) * S[k - 1] + S[n % k] + x;
    // for (int i = 1; i <= n; i++){
    //     b_t[i] = (i / k) * S[k - 1] + S[i % k] + x;
    // }

    // for (int i = 0; i < k; i++) {
    //     a[i] %= m;
    // }
    // while (n <= 1000) {
    int ans = 0;
    b[0] = x;
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[(i - 1) % k];
        // debug(b[i]);
        // debug(b_t[i]);
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        if (b[i] % m <= b[i + 1] % m) {
            ans++;
        }
    }
    // debug(n);
    cnt[ans]++;
    cout << ans << endl;

    // n++;
    // }
    // for (int i = 2; i <= 100; i++) {
    //     cout << i << " : " << cnt[i] << endl;
    // debug(cnt[i]);
    // }
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