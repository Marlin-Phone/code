// https://www.luogu.com.cn/problem/P1308
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a1, a2, n, d;
    long long S = 0;

    cin >> a1 >> a2 >> n;

    d = a2 - a1;
    S = n * a1 + (n * (n - 1) * d / 2);
    cout << S;

    return 0;
}