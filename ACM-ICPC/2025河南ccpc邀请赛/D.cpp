#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

void solve() {
    ll n;
    cin >> n;
    if ((ll)sqrt(n) * sqrt(n) == n) {
        ll now = 0;
        while (n) {
            now += n % 10;
            n /= 10;
        }
        n = now;
        if ((ll)sqrt(n) * sqrt(n) == n) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}