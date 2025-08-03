#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(x) for (ll i = 1; i <= x; ++i)
#define f1(x) for (ll j = 1; j <= x; ++j)
#define lowbit(x) ((-x) & x)
#define PII pair<ll, ll>
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define eps 1e-7
#define il inline

constexpr ll mod = 1e9 + 7;

il void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt = count(s.begin(), s.end(), '1');
    if (cnt == 0) {
        cout << string(k, '0') << '\n';
        return;
    }
    vector<ll> dp(cnt + 1);
    dp[0] = 1;
    // dp转移的方向有问题，前面转到后面考虑到不能是统一列的转移
    for (ll i = 1; i < 20; i++) {
        for (ll j = cnt; j >= 0; j--) {
            if (dp[j] && j + ((1ll << i) - (i + 1 <= k ? 1 : 0)) <= cnt) {
                dp[j + ((1ll << i) - (i + 1 <= k ? 1 : 0))] =
                    dp[j] | (1ll << i);
            }
        }
    }
    // cout << dp[cnt] << '\n';
    if (dp[cnt]) {
        // 只需要后面的k位
        cout << bitset<64>(dp[cnt]).to_string().substr(64 - k, k - 1) << 0
             << '\n';
    } else {

        cout << "None\n";
    }
}

int main() {
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}