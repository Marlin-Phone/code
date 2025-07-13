#pragma GCC optimize(O2)
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
constexpr ll mod = 1e9 + 7;
ll n, m, k;
ll ksm(ll x, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) {
            res = res * x % mod;
        }
        k >>= 1;
        x = x * x % mod;
    }
    return res;
}
ll inv(ll x) { return ksm(x, mod - 2); }

void solve() {

    cin >> n >> m >> k;
    ll sum = 1;
    if (k == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 1) {
        sum *= ksm(k, m);
    } else {
        sum = ksm(k, m) * (ksm(2, m + 1) - 1) % mod;
        // cout << sum << '\n';
        ll now;
        if (k != 2) {
            now = (ksm(k - 1, m) + mod - 1) * inv(k - 2) % mod + ksm(k - 1, m);
            now %= mod;
        } else if (k == 2) {
            now = m + 1;
        }

        sum *= ksm(now, n - 2);
        sum %= mod;
    }

    cout << sum << '\n';
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