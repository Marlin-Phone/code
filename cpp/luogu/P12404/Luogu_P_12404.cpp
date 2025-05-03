// https://luogu.com.cn/problem/P12404
// 贪心 数学
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// const int N =
int n, t, x;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t >> x;
    cout << min(n, 2ll * x * t) << " " << max(2ll, x);

    return 0;
}