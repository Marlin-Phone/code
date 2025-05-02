// https://luogu.com.cn/problem/P3879
// set 集合 STL
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e3 + 10;
int n;
int num;
set<string> st[N];
int m;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        for (int j = 1; j <= num; j++) {
            string word;
            cin >> word;
            st[i].insert(word);
        }
    }

    cin >> m;
    while (m--) {
        string target;
        cin >> target;
        for (int i = 1; i <= n; i++) {
            if (st[i].count(target) == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}