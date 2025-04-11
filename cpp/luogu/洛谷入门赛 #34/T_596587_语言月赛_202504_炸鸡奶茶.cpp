// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int f, m, n;
int ans = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> f >> m >> n;
    n--;
    int week = n / 7;
    ans += week * (2 * f + m);

    int day = n % 7;
    if (day == 6) {
        ans += 2 * f + m;
    }
    // cout << "day = " << day << endl;

    cout << ans;

    return 0;
}