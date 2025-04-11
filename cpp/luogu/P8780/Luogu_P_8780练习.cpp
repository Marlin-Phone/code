// https://luogu.com.cn/problem/P8780
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// const int N =
int a, b, n;
int day = 0;
int qus = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n;
    day = (n / (a * 5 + b * 2)) * 7;
    n %= (a * 5 + b * 2);
    int i = 1;
    while (n > 0) {
        if (i <= 5) {
            day++;
            n -= a;
        } else {
            day++;
            n -= b;
        }
        i++;
    }

    cout << day;

    return 0;
}