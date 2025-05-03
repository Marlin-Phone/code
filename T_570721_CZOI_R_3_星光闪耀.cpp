#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int MAX_FACT = 5e6 + 10;

ll fact[MAX_FACT], inv_fact[MAX_FACT];

ll pow_mod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_FACT - 1] = pow_mod(fact[MAX_FACT - 1], MOD - 2, MOD);
    for (int i = MAX_FACT - 2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll comb(int a, int b) {
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;

        if (k == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (m == 0) {
            cout << pow_mod(k, n, MOD) << '\n';
            continue;
        }

        if (k == 1) {
            ll ans = comb(m + n - 1, m - 1);
            cout << ans << '\n';
            continue;
        }

        ll inv_k = pow_mod(k, MOD - 2, MOD);
        ll current_term = pow_mod(k, n, MOD);
        ll sum_part = current_term;

        for (int p = 1; p <= n - 1; ++p) {
            ll numerator = (ll)(m - 1 + p) % MOD;
            ll denominator = p % MOD;
            ll inv_denominator = pow_mod(denominator, MOD - 2, MOD);
            ll factor = numerator * inv_denominator % MOD;
            factor = factor * inv_k % MOD;
            current_term = current_term * factor % MOD;
            sum_part = (sum_part + current_term) % MOD;
        }

        cout << sum_part % MOD << '\n';
    }

    return 0;
}