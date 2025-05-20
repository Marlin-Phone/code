// https://luogu.com.cn/problem/P9872
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e5 + 10;
int T = 1;
int n;
struct TreeNode {
    int deepth;
    vector<int> chil;
    int length; // 树的结点个数
} Node[N];

int getdeepth(int idx, int deepth) {
    if (idx == 0) {
        return 0;
    }
    Node[idx].deepth = deepth;
    Node[idx].length = 1;

    for (int i = 0; i < Node[idx].chil.size(); i++) {
        Node[idx].length += getdeepth(Node[idx].chil[i], deepth + 1);
    }
    return Node[idx].length;
}
// void dfs(int idx) {
//     if (idx == 0) {
//         return;
//     }
//     cout << Node[idx].deepth << " " << n - Node[idx].length + 1 << endl;
//     for (int i = 0; i < Node[idx].chil.size(); i++) {
//         dfs(Node[idx].chil[i]);
//     }
// }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            Node[i].chil.clear();
        }
        for (int i = 1; i <= n - 1; i++) {
            int x, y;
            cin >> x >> y;
            Node[x].chil.push_back(y);
        }
        getdeepth(1, 1);
        // dfs(1);
        for (int i = 1; i <= n; i++) {
            cout << Node[i].deepth << " " << n - Node[i].length + 1 << endl;
        }
    }
    return 0;
}