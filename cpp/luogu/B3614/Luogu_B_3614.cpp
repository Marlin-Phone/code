// https://luogu.com.cn/problem/B3614
// 栈 unsigned long long
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int unsigned long long

const int N = 1e6 + 10;
int T = 1;
int n;

void solve() {
    stack<int> stk;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push") {
            int x;
            cin >> x;
            stk.push(x);
        } else if (str == "query") {
            if (!stk.empty()) {
                cout << stk.top() << endl;
            } else {
                cout << "Anguei!" << endl;
            }
        } else if (str == "size") {
            cout << stk.size() << endl;
        } else if (str == "pop") {
            if (!stk.empty()) {
                stk.pop();
            } else {
                cout << "Empty" << endl;
            }
        }
    }
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