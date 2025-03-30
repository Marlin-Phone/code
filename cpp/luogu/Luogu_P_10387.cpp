#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int n, S;       // 士兵数量 进行一次组团训练所需的金币数
int p[N], c[N]; // 第i名士兵一次训练成本 成为战士需要的训练次数

bool check(int mid) {}
signed main() {
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
    }

    int l = -1, r = 1e6 + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {

        } else {
        }
    }

    return 0;
}