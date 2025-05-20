// https://luogu.com.cn/problem/P1364
// 最短路 BFS 树形数据结构
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 110;
int T = 1;
int n;
struct TreeNode {
    int w;
    int fa; // 父亲结点
    int u;  // 左子结点
    int v;  // 右子结点
} Node[N];
int flag[N];
queue<pair<TreeNode, int>> q; // 结点 距离
long long sum = 0;
long long minsum = 1e18;

void setfa(int idx, int fa) {
    if (idx == 0) {
        return;
    }
    Node[idx].fa = fa;
    setfa(Node[idx].u, idx);
    setfa(Node[idx].v, idx);
}

void bfs(int idx) {
    // 初始化
    int dis = 0;
    memset(flag, 0, sizeof(flag));
    q.push({Node[idx], dis});
    flag[idx] = 1;
    sum = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        auto node = t.first; // 该结点
        int dist = t.second; // 距原点距离

        sum += node.w * dist;
        // 父结点 fa
        if (flag[node.fa] == 0) {
            q.push({Node[node.fa], dist + 1});
            flag[node.fa] = 1;
        }
        // 左子结点 u
        if (flag[node.u] == 0) {
            q.push({Node[node.u], dist + 1});
            flag[node.u] = 1;
        }
        // 右子结点 v
        if (flag[node.v] == 0) {
            q.push({Node[node.v], dist + 1});
            flag[node.v] = 1;
        }
    }
    minsum = min(sum, minsum);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> Node[i].w >> Node[i].u >> Node[i].v;
        }
        setfa(1, 0);
        for (int i = 1; i <= n; i++) {
            bfs(i);
        }
        cout << minsum;
    }
    return 0;
}