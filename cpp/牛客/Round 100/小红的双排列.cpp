// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n;
vector<int> vec;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
        vec.push_back(i);
    }
    for (int i = 0; i < n * 2; i++) {
        cout << vec[i] << " ";
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