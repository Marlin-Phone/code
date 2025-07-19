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
string s, temp;
bool flag[N];

void solve() {
    cin >> temp;
    s = " ";
    s += temp;

    for (int i = 1; i <= temp.size(); i++) {
        if (s[i] == '#' && flag[i] == false) {
            cout << i << ',';
            flag[i] = true;
            int j = i + 1;
            while (s[j] != '#') {
                j++;
            }
            cout << j << endl;
            flag[j] = true;
        }
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