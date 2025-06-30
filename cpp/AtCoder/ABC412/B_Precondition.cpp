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
string S, T0;
queue<char> q;

bool check(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return true;
    }
    return false;
}
void solve() {
    cin >> S;
    cin >> T0;
    // int flag = 1;
    for (int i = 1; i < S.size(); i++) {
        if (check(S[i])) {
            char to_find = S[i - 1];
            q.push(to_find);
        }
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int flag = 0;
        for (int i = 0; i < T0.size(); i++) {
            if (t == T0[i]) {
                flag = 1;
            }
        }
        if (flag == 1) {
            continue;
        } else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

    return;
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