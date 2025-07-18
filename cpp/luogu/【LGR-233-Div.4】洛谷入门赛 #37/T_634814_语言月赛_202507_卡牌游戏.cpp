// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
// #define MOD 1000000007

const int N = 2e5 + 10;
int T = 1;
int n, k;
int idx[N];
list<int> a;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> idx[i];
    }
    int l = 1, r = k + 1;
    int i = n;
    while (l <= k && r <= n) {
        a.push_back(idx[l++]);
        a.push_back(idx[r++]);
    }
    while (l != k + 1) {
        a.push_back(idx[l++]);
    }
    while (r != n + 1) {
        a.push_back(idx[r++]);
    }
    for (auto it : a) {
        cout << it << " ";
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