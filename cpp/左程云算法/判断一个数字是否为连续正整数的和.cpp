// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;
bool getnum1(int num) {
    for (int start = 1, sum; start <= num; start++) {
        sum = start;
        int plus = start + 1;
        while (plus <= num) {
            if (sum + plus > num) {
                break;
            }
            if (sum + plus == num) {
                return true;
            }
            sum += plus;
            plus++;
        }
    }
    return false;
}
bool getnum2(int num) {
    return (num & (num - 1)) != 0; // 判读num是否是2的幂
}
void solve() {
    // for (int i = 1; i <= 200; i++) {
    //     if (getnum1(i) == getnum2(i)) {
    //         cout << i << " : " << "YES" << endl;
    //     } else {
    //         cout << i << " : " << "NO" << endl;
    //     }
    // }
    cin >> n;
    if (getnum2(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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