// https://www.luogu.com.cn/problem/P1161
#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int n, t;
int flag[N];
double a;

int main() {
    cin >> n;
    while (n--) {
        cin >> a >> t;
        for (int i = 1; i <= t; i++) {
            int x = i * a; // 向下取整
            flag[x] ^= 1;  // 异或
        }
    }

    int i = 1;
    while (1) {
        if (flag[i] == 1) {
            cout << i << endl;
            break;
        }
        i++;
    }

    return 0;
}