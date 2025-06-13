// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

// const int N =
int T = 1;
int n;

int getmoney(int x) {
    if (x <= 10) {
        return x * 20;
    } else if (x > 10 && x <= 50) {
        return 10 * 20 + ((x - 10 + 4) / 5) * 80;
    } else if (x > 50) {
        return 10 * 20 + 40 / 5 * 80 + ((x - 50 + 9) / 10) * 120;
    }
}
void solve() {
    cin >> n;
    int money = 0;
    int minmoney = 1e9;
    for (int i = 0; i <= n; i++) {
        int j = n - i;
        money = getmoney(i) + getmoney(j);
        minmoney = min(minmoney, money);
    }
    cout << minmoney;
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