// https://luogu.com.cn/problem/P4913
// 二叉树 树的深度 深度优先遍历
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e6 + 10;
int n;
struct TreeNode {
    int lc, rc;

} node[N];
int ans = 0;

void dfs(int id, int deep) {
    if (id == 0) {
        return;
    }

    ans = max(ans, deep);
    dfs(node[id].lc, deep + 1);
    dfs(node[id].rc, deep + 1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].lc >> node[i].rc;
    }
    dfs(1, 1);
    cout << ans;

    return 0;
}