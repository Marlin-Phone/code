// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int A, B;

void solve() {
    cin >> A >> B;
    double temp0 = 1.0 * A / B;
    int temp1 = A / B;
    int temp2 = A / B + 1;
    double dif1 = abs(temp1 - temp0);
    double dif2 = abs(temp2 - temp0);
    // debug(temp0);
    // debug(dif1);
    // debug(dif2);
    if (dif1 < dif2) {
        cout << temp1;
    } else {
        cout << temp2;
    }
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