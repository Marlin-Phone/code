// https://luogu.com.cn/problem/P8835
// 字符串
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int T;
int n, m;
string a, b;

bool check(int l, int r) {
    for (int i = l, idx = 0; i <= r; i++, idx++) {
        if (b[i] != a[idx]) {
            return false;
        }
    }

    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int cnt = 0;
        cin >> n >> m;
        cin >> a;
        cin >> b;

        if (b.size() - a.size() < 0) {
            cout << 0;
        }

        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= 'Z' && a[i] >= 'A') {
                a[i] = a[i] - 'A' + 'a';
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] <= 'Z' && b[i] >= 'A') {
                b[i] = b[i] - 'A' + 'a';
            }
        }

        for (int i = 0; i < b.size() - a.size() + 1; i++) {
            if (check(i, i + a.size() - 1)) {
                cnt++;
            } else {
                continue;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}