// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e5 + 10;
int T = 1;
int n, k;
int a[N];
vector<int> nums;

void solve() {
    int cnt = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = l;
    while (l <= n && r <= n) {
        r = l + k - 1;
        if (r > n) {
            break;
        }

        bool all_good = true;
        for (int j = l; j <= r; j++) {
            if (a[j] == 1) {
                all_good = false;
                break;
            }
        }

        if (all_good) {
            cnt++;
            l = r + 2;
        } else {
            l++;
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