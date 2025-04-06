// https://luogu.com.cn/problem/P10424
// 2024蓝桥杯B组第一道程序设计题-好数
#include <bits/stdc++.h>
using namespace std;
#define int long long

// const int N =
int n;
int cnt = 0;

bool isgoodnum(int num) {
    int wei = 1;
    int temp;
    while (num > 0) {
        temp = num % 10;
        num /= 10;
        if (wei % 2 == 1) { // 奇数位
            if (temp % 2 == 1) {

            } else {
                return false;
            }
        } else if (wei % 2 == 0) { // 偶数位
            if (temp % 2 == 0) {

            } else {
                return false;
            }
        }
        wei++;
    }

    return true;
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (isgoodnum(i)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}