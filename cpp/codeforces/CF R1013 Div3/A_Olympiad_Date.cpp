// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n;
// 01032025
bool check(vector<int> &num) {

    bool flag = 0;
    if (num[0] >= 3 && num[1] >= 1 && num[2] >= 2 && num[3] >= 1 &&
        num[5] >= 1) {
        flag = 1;
    }
    return flag;
}

void solve() {
    int ans = 0;
    cin >> n;
    // debug(n);
    bool flag = 0;
    vector<int> a(n + 10, 0);
    vector<int> num(15, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // debug(i);
        // debug(a[i]);
        num[a[i]]++;
        if (check(num) && flag == 0) {
            flag = 1;
            ans = i;
            // break;
        } else {
            continue;
        }
    }

    if (flag == 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
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