// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 110;
int T = 1;
string n;
int nums[N];

void solve() {
    cin >> n;
    int idx = n.size() - 1;
    int cnt = 0;
    while (n[idx] == '0') {
        idx--;
        cnt++;
    }
    for (int i = idx - 1; i >= 0; i--) {
        if (n[i] != '0') {
            cnt++;
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