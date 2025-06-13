// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
#define int long long

const int N = 1e5 + 10;
int T = 1;
int n;
int a[N];
int ans[N];

int func(int num) {
    int res = 0;
    while (num != 0) {
        res += num % 10;
        num /= 10;
    }
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int i0 = a[i];
        ans[i] = i;
        while (i0--) {
            int temp0 = ans[i];
            ans[i] = func(ans[i]);
            int temp1 = ans[i];
            if (temp0 == temp1) {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}