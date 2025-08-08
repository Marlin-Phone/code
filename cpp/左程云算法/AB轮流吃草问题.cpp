// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;
// 1 4 16 64
string f(int rest, string cur) {
    string enemy = cur == "A" ? "B" : "A";
    if (rest < 5) {
        return (rest == 0 || rest == 2) ? enemy : cur;
    }
    int pick = 1;
    while (pick <= rest) {
        if (f(rest - pick, enemy) == cur) {
            return cur;
        }
        pick *= 4;
    }
    return enemy;
}
string win1(int n) { return f(n, "A"); }
string win2(int n) {
    n %= 5;
    if (n == 0 || n == 2) {
        return "B";
    } else {
        return "A";
    }
}
void solve() {
    // 打表找规律过程
    // for (int i = 0; i <= 50; i++) {
    //     cout << i << " : " << win1(i) << endl;
    // }
    cin >> n;
    cout << win2(n) << endl;
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
