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
const int N = 1e5 + 10;

ll n, k;
bool st[N];
bool flag = false;

void dfs(int x, int k) {
    if (flag == true) {
        return;
    }
    if (k < 0) {
        return;
    }
    if (x >= n) {
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                if (st[i] == 0) {
                }
            }
        }

        return;
    }
    st[x] = true; // 1
    dfs(x + 1, k - 1);
    st[x] = false; // 0
    dfs(x + 1, k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    k = n - k;
    for (int i = 1; i <= k; i++)
        cout << 2;
    for (int i = k + 1; i <= n; i++)
        cout << 3;
}

int main() {
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}