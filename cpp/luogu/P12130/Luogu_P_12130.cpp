// https://luogu.com.cn/problem/P12130
// 数学
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    // x = 233, y = 666;
    double r = pow(233 * 233 + 666 * 666, 1.0 / 2);
    // printf("%lf\n", r);
    double myatan = atan(1.0 * 666 / 233);
    // printf("%lf\n", myatan);
    double ans = r + r * myatan;
    // printf("%lf\n", ans);
    cout << 1576;

    return 0;
}