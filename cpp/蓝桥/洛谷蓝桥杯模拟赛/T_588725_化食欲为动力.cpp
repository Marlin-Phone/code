#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 210;
int n, m, k;          // n个面包 m包火腿肠 k盒牛奶
int a[N], b[N], c[N]; // 面包 火腿肠 牛奶 的食欲
int maxnum = -1;

signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int t = 1; t <= k; t++) { // 变量为t
                int temp = (a[i] * b[j]) % c[t];
                maxnum = max(maxnum, temp);
            }
        }
    }

    cout << maxnum;

    return 0;
}