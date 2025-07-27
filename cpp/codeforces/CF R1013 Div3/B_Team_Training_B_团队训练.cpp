// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n, x;
int a[N];
bool cmp(int a, int b) { return a > b; }

void solve() {
    int cnt = 0;
    int size = 0;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n, cmp);

    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        size += 1;
        if (a[i] * size >= x) {
            cnt += 1;
            size = 0;
        }
    }
    cout << cnt << endl;
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