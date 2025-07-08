// https://luogu.com.cn/problem/B3616
// 队列
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n;
queue<int> que;

void solve() {
    cin >> n;
    while (n--) {
        int ch;
        cin >> ch;
        switch (ch) {
        case 1: {
            int x;
            cin >> x;
            que.push(x);
            break;
        }
        case 2: {
            if (que.empty()) {
                cout << "ERR_CANNOT_POP" << endl;
            } else {
                que.pop();
            }
            break;
        }
        case 3: {
            if (que.empty()) {
                cout << "ERR_CANNOT_QUERY" << endl;
            } else {
                cout << que.front() << endl;
            }
            break;
        }
        case 4: {
            cout << que.size() << endl;
            break;
        }
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