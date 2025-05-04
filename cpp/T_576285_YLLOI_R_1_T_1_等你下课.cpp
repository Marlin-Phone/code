// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e6 + 10;
int n, k;
int S = 0;
int temp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        S += temp;
    }

    // cout << (n - 1) * k + 1 << endl;
    // cout << S << endl;
    // cout << n * k << endl;
    if (n == 1) {
        cout << S;
    } else if ((n - 1) * k + 1 <= S && S <= n * k) {
        if (S == n * k) {
            cout << k;
        } else {
            cout << S % k;
        }
    } else {
        cout << 0;
    }

    return 0;
}