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
int f(int rest) {
    if (rest < 0) {
        return INT_MAX;
    }
    if (rest == 0) {
        return 0;
    }
    int p1 = f(rest - 8);
    int p2 = f(rest - 6);
    p1 += p1 != INT_MAX ? 1 : 0;
    p2 += p2 != INT_MAX ? 1 : 0;
    return min(p1, p2);
}
int bags1(int apple) {
    int ans = f(apple);
    return ans == INT_MAX ? -1 : ans;
}
int bags2(int apple) {
    if (apple % 2 == 1) {
        return -1;
    }
    if (apple < 18) {
        if (apple == 0) {
            return 0;
        }
        if (apple == 6 || apple == 8) {
            return 1;
        }
        if (apple == 12 || apple == 14 || apple == 16) {
            return 2;
        }
        return (apple - 18) / 8 + 3;
    }
}
void solve() {
    for (int i = 0; i <= 100; i++) {
        cout << "i = " << i << " : ";
        cout << bags1(i) << endl;
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