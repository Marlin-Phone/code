// https://luogu.com.cn/problem/P5318
// 图的建立 DFS BFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

// const int N =
int T = 1;
int n, m; // 节点个数 引用个数
struct edge {
    int u, v; // 记录边的结构体, u起点, v终点
};
vector<int> e[100001]; // 存具体信息的二维vector
vector<edge> s;        // 存边的结构体vector数组
bool cmp(edge x, edge y) {
    if (x.v == y.v) {
        return x.u < y.u;
    }
    return x.v < y.v;
}

bool vis1[100001] = {0}; // 用于dfs
bool vis2[100001] = {0}; // 用于bfs

void dfs(int x) {
    vis1[x] = 1;
    cout << x << " ";
    for (int i = 0; i < e[x].size(); i++) {
        int point = s[e[x][i]].v;
        if (!vis1[point]) {
            dfs(point);
        }
    }
}
void bfs(int x) {
    queue<int> q;
    q.push(x);
    cout << x << " ";
    vis2[x] = 1;
    while (!q.empty()) {
        int fro = q.front();
        for (int i = 0; i < e[fro].size(); i++) {
            int point = s[e[fro][i]].v;
            if (!vis2[point]) {
                q.push(point);
                cout << point << " ";
                vis2[point] = 1;
            }
        }
        q.pop();
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        s.push_back({uu, vv}); // 为了排序,先存入vector
    }
    sort(s.begin(), s.end(), cmp); // 排序,从小到大
    for (int i = 0; i < m; i++) {
        cout << s[i].u << " " << s[i].v << endl;
    }

    for (int i = 0; i < m; i++) {
        e[s[i].u].push_back(i);
        // (i号边的起点s[i].u连接的边的数组)中存入i号边
        // 初始化e数组
    }
    dfs(1);
    cout << endl;
    bfs(1);
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