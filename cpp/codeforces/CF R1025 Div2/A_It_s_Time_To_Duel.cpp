// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e3 + 10;
int T, n;
int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool has_zero = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 0 && a[i + 1] == 0) {
                has_zero = true;
                break;
            }
        }

        if (has_zero == 1) {
            cout << "YES" << endl;
            continue;
        }

        if (n == 2 && a[0] == 1 && a[1] == 1) {
            cout << "YES" << endl;
            continue;
        }

        bool ones = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != 1) {
                ones = false;
                break;
            }
        }

        if (ones && n > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
