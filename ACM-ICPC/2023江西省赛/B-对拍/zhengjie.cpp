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
int Sbn;

void solve() {
    int ans = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    cin >> n >> m >> x;
    for (int i = 0; i < k; i++) {
        a[i] %= m;
    }
    S[0] = 0;
    for (int i = 0; i < k; i++) {
        S[i + 1] = S[i] + a[i];
    }
    // b[0] = x;
    // Sb[0] = x;
    // for (int i = 1; i <= n; i++) {
    //     b[i] = b[i - 1] + a[(i - 1) % k];
    //     Sb[i] = Sb[i - 1] + b[i];
    // }
    // for (int i = 0; i <= n; i++) {
    //     cout << b[i] << " ";
    //     b[i] %= m;
    // }
    // cout << endl << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl << endl;
    // for (int i = 1; i <= n; i++) {
    //     if (b[i - 1] % m <= b[i] % m) {
    //         ans++;
    //     }
    // }
    // if (n % k == 0) {
    //     Sbn = x + (n / k) * S[k - 1];
    // } else {
    //     Sbn = x + (n / k) * S[k - 1] + S[n % k - 1];
    // }
    Sbn = (n / k) * (S[k] / m) + ((n / k) * (S[k] % m) + x % m) / m +
          S[n % k] / m;
    // debug(Sbn);
    // debug(Sb[n]);
    // debug(Sbn);
    // debug(S[k - 1]);
    // cout << S[k - 1] << endl;
    cout << n - Sbn << endl;
    // cout << ans << endl;
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