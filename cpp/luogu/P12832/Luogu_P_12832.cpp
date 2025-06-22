// https://luogu.com.cn/problem/P12832
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e3 + 10;
int T = 1;
int n, k;
vector<int> vec(N);

void solve() {
    int n, k;
    cin >> n >> k;
    k %= n; // 对n取模，简化问题
    if (k == 0) {
        cout << 0 << endl; // 如果k为0，无需操作
        return;
    }
    if (n % 2 == 1) { // n为奇数
        if (k % 2 == 1) {
            cout << (n - k + 1) / 2 << endl; // k为奇数
        } else {
            cout << (2 * n - k) / 2 << endl; // k为偶数
        }
    } else { // n为偶数
        if (k % 2 == 1) {
            cout << -1 << endl; // k为奇数，无解
        } else {
            cout << (n - k) / 2 << endl; // k为偶数
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