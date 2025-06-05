// https://luogu.com.cn/problem/B3643
// 已知邻接矩阵求邻接表 邻接表求邻接矩阵
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

// const int N =
int T = 1;
int n, m;

void solve() {
    cin >> n >> m;

    // 邻接矩阵求邻接表
    // vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    // for (int i = 0; i < m; i++) {
    //     int uu, vv;
    //     cin >> uu >> vv;
    //     g[uu][vv]++;
    //     g[vv][uu]++;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> adj_list(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n;
    //          j++) { // 根据边数多次添加领居(如重边),该题只添加1个邻居(无重边)
    //         if (g[i][j] > 0) {
    //             for (int k = 0; k < g[i][j]; k++) {
    //                 adj_list[i].push_back(j);
    //             }
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << adj_list[i].size() << " ";
    //     for (int j = 0; j < adj_list[i].size(); j++) {
    //         cout << adj_list[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 邻接表求邻接矩阵
    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        adj_list[uu].push_back(vv);
        adj_list[vv].push_back(uu);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int it : adj_list[i]) {
            matrix[i][it]++;
            // matrix[it][i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << adj_list[i].size() << " ";
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
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