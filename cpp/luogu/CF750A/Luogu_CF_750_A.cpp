// https://luogu.com.cn/problem/CF750A
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n, k;
int sum = 0;
int tim = 0;

bool check(int mid) {
    if (mid > n) {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= mid; i++) {
        sum += i * 5;
    }
    if (sum > tim) {
        return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    tim = 240 - k;

    int l = 0, r = 240;
    while (l + 1 != r) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
    // int i = 0;
    // while (sum <= tim) {
    //     i++;
    //     sum += i * 5;
    //     // if (i > n) {
    //     //     break;
    //     // }
    // }
    // i--;
    // if (i > n) {
    //     cout << n;
    // } else {
    //     cout << i;
    // }
    return 0;
}