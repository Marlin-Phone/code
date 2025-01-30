// https://www.luogu.com.cn/problem/P1028
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int count = 1;

int main() {
    int n;
    int f[N] = {1, 1};
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            f[i] = f[i - 1] + f[i / 2];
        } else {
            f[i] = f[i - 1];
        }
    }

    cout << f[n] << endl;
    return 0;
}