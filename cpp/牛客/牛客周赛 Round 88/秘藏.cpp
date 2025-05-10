// https://luogu.com.cn/problem/P10424
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int n;          // 点的数量
int k;          // 消耗的金币数量
int a[N], b[N]; // 表,里世界第i点的金币数量

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

        return 0;
}