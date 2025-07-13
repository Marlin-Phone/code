// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n, a, b, x, y, p;
set<int> st;

void solve() {
    int sum = 0;
    int cost = 0;
    cin >> a >> b >> x >> y >> p;
    for (int i = 0; i <= p / x; i++) {
        for (int j = 0; j <= p / y; j++) {
            if (i * x + j * y <= p) {
                st.insert((a + i) * (b + j));
            }
        }
    }
    cout << st.size();
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