// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e5 + 10;
int m, n; // n个正整数 是m的倍数
int nums[N];
int flag = 0;

bool func(int num) {
    if (num % m == 0) {
        return false;
    }

    int sumwei = 0;
    while (num > 0) {
        sumwei += num % 10;
        num /= 10;
    }

    if (sumwei % m == 0) {
        return true;
    }

    return false;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (func(nums[i]) == true) {
            flag = 1;
            cout << nums[i] << endl;
        }
    }

    if (flag == 0) {
        cout << "None";
    }

    return 0;
}