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

void solve() {
    cin >> n;
    int h = n / 60;
    int m = n % 60;
    cout << "|" << h / 10 << "|" << h % 10 << "|:|" << m / 10 << "|" << m % 10
         << "|";
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