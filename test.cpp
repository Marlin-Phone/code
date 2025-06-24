#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(a) cout << #a << " = " << a << endl;

signed main() {
    int n;
    cin >> n;

    vector<int> inDegree(n + 10, 0); // 记录每个结点的入度
    queue<int> q;                    // 队列记录入度为0的结点
    vector<int> topoSort;            // 拓扑排序结果
    vector<int> g[n + 10];           // 邻接表

    for (int i = 1; i <= n; i++) { // 建图并记录入度
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv); // 建立邻接表
        inDegree[vv]++;      // 记录每个结点的入度
    }
    for (int i = 1; i <= n; i++) { // 初始化入度为0的队列
        if (inDegree[i] == 0) {
            q.push(i); // 入度为0的结点入队列
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoSort.push_back(u); // 拓扑排序结果
        for (int v : g[u]) {
            inDegree[v]--; // 减少每个邻接点的入度
            if (inDegree[v] == 0) {
                q.push(v); // 入度为0的邻接点入队列
            }
        }
    }
    if (topoSort.size() == n) { // 判断是否有环
        cout << "No" << endl;   // 无环
    } else {
        cout << "Yes" << endl; // 有环
    }
    for (int u : topoSort) {
        cout << u << " "; // 输出拓扑排序结果
    }
    return 0;
}