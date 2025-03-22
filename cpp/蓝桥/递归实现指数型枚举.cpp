#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> arr(N);
int n;
int st[N];
// int ways[1 << 15][16];
int cnt;
vector<vector<int>> ways;

void dfs(int x) {
    if (x > n) {
        vector<int> way;
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                // ways[cnt][i] = i;
                way.push_back(i);
            }
        }
        ways.push_back(way);
        cnt++;
        return;
    }

    st[x] = 1; // 选
    dfs(x + 1);

    st[x] = 0; // 回溯

    dfs(x + 1);
    st[x] = 2; // 不选
}
int main() {
    cin >> n;
    // cout << "text" << endl;
    dfs(1);
    // for (int i = 0; i < cnt; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (ways[i][j] != 0)
    //             cout << ways[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < ways.size(); i++) {
        for (int j = 0; j < ways[i].size(); j++) {
            cout << ways[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}