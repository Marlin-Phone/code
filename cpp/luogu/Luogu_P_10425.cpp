// https://luogu.com.cn/problem/P10425
// 高精度
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
double d;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    int cheng = pow(2, n);
    double ans0 = d * cheng;
    if (ans0 - floor(ans0) < 0.5) {
        ans0 = floor(ans0);
    } else {
        ans0 = floor(ans0) + 1;
    }
    cout << ans0;

    return 0;
}