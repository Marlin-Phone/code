// https://luogu.com.cn/problem/P1113
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e4 + 10;
int T = 1;
int n;
// struct node{
//     vector<int> neighbor;
//     int val;
// };
vector<int> inDegree(N);
vector<int> g[N];
queue<int> q;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int uu;
        int val;
        while (1) {
            int vv;
            cin >> vv;
            if (vv == 0) {
                break;
            }
            g[vv].push_back(uu);
            inDegree[uu]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < vec[i].size(); j++) {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
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