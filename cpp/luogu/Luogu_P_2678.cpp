#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int l, n, m;
int D[N];
int diff[N];

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (diff[i] < x && diff[i] != -1) {
            diff[i + 1] += diff[i]; // 更改后一个石头的距离
            diff[i] = -1;           // 该石头被移走
            cnt++;                  // 次数++
        }
    }
    if (cnt > m) {
        return false;
    }

    return true;
}
int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
        diff[i] = D[i] - D[i - 1];
    }
    diff[n + 1] = l - D[n]; // 最后一块石头的距离

    int l = 0, r = 1e9 + 10;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid; // 符合条件
            cout << "l = " << l << endl;
        } else {
            r = mid;
            cout << "r = " << r <<
        }
    }

    cout << l;

    return 0;
}