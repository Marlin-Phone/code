// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e6 + 10;
int T = 1;
int n;
int a[N];
// stack<int> stk;
list<int> lst;

void solve() {
    lst.clear();

    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        int temp;
        cin >> temp;
        if (!lst.empty()) {
            int a = lst.front();
            if (a == temp) {
                lst.clear();
            }
        } else {
            lst.push_back(temp);
        }
    }

    // while (!lst.empty()) {
    //     cout << lst.front() << " ";
    //     lst.pop_front();
    // }

    if (lst.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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