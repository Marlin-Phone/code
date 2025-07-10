#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, q;
int parent[N];
queue<int> que;
int depth[N];
vector<int> g[N];
int visited[N];

void bfs(int root) {
    que.push(root);
    parent[root] = 0;
    depth[root] = 1;
    visited[root] = 1;
    while (!que.empty()) {
        auto u = que.front();
        que.pop();
        for (auto v : g[u]) {
            if (visited[v]) {
                continue;
            }
            depth[v] = depth[u] + 1;
            visited[v] = 1;
            que.push(v);
        }
    }
}
int getLCA(int a, int b) {
    while (depth[a] > depth[b]) {
        a = parent[a];
    }
    while (depth[a] < depth[b]) {
        b = parent[b];
    }
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int temp;
        cin >> temp;
        g[i].push_back(temp);
        g[temp].push_back(i);
        parent[i] = temp;
    }
    bfs(1);
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
    cout << "test" << endl;
    return 0;
}