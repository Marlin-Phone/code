// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 2e5 + 10;
int T = 1;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 边界条件处理
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }

    // 防止除零错误
    if (n + 1 == 0) {
        cout << "NO" << endl;
        return;
    }

    // 检查整除性
    if ((2 * a[1] - a[2]) % (n + 1) != 0) {
        cout << "NO" << endl;
        return;
    }

    // 计算理论值
    int f2 = (2 * a[1] - a[2]) / (n + 1);
    int f1 = a[1] - n * f2;

    // 验证非负性
    if (f1 < 0 || f2 < 0) {
        cout << "NO" << endl;
        return;
    }

    // 验证所有元素（从第三项开始）
    for (int i = 3; i <= n; i++) {
        int expect = i * f1 + (n - i + 1) * f2;
        if (expect != a[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    // 验证前两项（冗余检查确保正确性）
    if (a[1] != f1 + n * f2 || a[2] != 2 * f1 + (n - 1) * f2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}