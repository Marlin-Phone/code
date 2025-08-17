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
    vector<ll> a(n + 1);
    ll maxx = -1e18;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }

    ll sum = accumulate(a.begin(), a.end(), 0ll) + k;
    vector<ll> sieve;
    for (ll i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            sieve.push_back(i);
            if (i * i != sum)
                sieve.push_back(sum / i);
        }
    }
    ll ans = 1;
    for (ll y : sieve) {
        if (y <= maxx) {
            ll cnt = 0;
            for (ll i = 1; i <= n; i++) {
                if (a[i] % y)
                    cnt += (y - a[i] % y);
                if (cnt > k) {
                    break;
                }
            }
            if (cnt <= k) {
                ans = max(ans, y);
            }
        } else {
            if (sum / y >= n) {
                ans = max(ans, y);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}