// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int x, k;

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }

    for (int i = 2; i * i <= num + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> x >> k;
    if (k == 1) {
        if (isPrime(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (x == 1 && k == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}