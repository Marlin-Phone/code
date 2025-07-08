// https://luogu.com.cn/problem/B3656
// 双端队列 卡常 list
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e6 + 10;
int T = 1;
int q;
// vector<deque<int>> dque(N);
map<int, list<int>> dque; // 使用dqueue会被卡常!

void solve() {
    string str;
    cin >> q;
    while (q--) {
        cin >> str;
        if (str == "push_back") {
            int a, x;
            cin >> a >> x;
            dque[a].push_back(x);
        } else if (str == "pop_back") {
            int a;
            cin >> a;
            if (!dque[a].empty()) {
                dque[a].pop_back();
            }
            if (dque[a].empty()) {
                dque.erase(a);
            }
        } else if (str == "push_front") {
            int a, x;
            cin >> a >> x;
            dque[a].push_front(x);
        } else if (str == "pop_front") {
            int a;
            cin >> a;
            if (!dque[a].empty()) {
                dque[a].pop_front();
            }
            if (dque[a].empty()) {
                dque.erase(a);
            }
        } else if (str == "size") {
            int a;
            cin >> a;
            cout << dque[a].size() << endl;
        } else if (str == "front") {
            int a;
            cin >> a;
            if (!dque[a].empty()) {
                cout << dque[a].front() << endl;
            }
            if (dque[a].empty()) {
                dque.erase(a);
            }
        } else if (str == "back") {
            int a;
            cin >> a;
            if (!dque[a].empty()) {
                cout << dque[a].back() << endl;
            }
            if (dque[a].empty()) {
                dque.erase(a);
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