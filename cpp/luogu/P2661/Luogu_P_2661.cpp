// https://luogu.com.cn/problem/P2661
// 图中最小的环 拓扑排序 DFS set
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n;
int to[N];
vector<int> g[N];
vector<int> topo;
int inDegree[N];
queue<int> q;
set<int> st;
int isVisited[N];
vector<int> ans;

void dfs(int u, int cnt) {
    // if(x > n){
    //     return;
    // }
    if (isVisited[u]) {
        ans.push_back(cnt);
        return;
    }
    isVisited[u] = 1;
    for (auto v : g[u]) {
        dfs(v, cnt + 1);
    }
}
void topoSort() {
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            topo.push_back(i);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (--inDegree[v] == 0) {
                topo.push_back(v);
                q.push(v);
            }
        }
    }
}
void solve() {
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        g[u].push_back(v);
        inDegree[v]++;
    }
    topoSort();                             // V + E
    for (int i = 0; i < topo.size(); i++) { // nlogn
        st.insert(topo[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (st.count(i) == 0 && !isVisited[i]) {
            dfs(i, 0);
        }
    }
    int minans = 1e9;
    for (int i = 0; i < ans.size(); i++) {
        minans = min(minans, ans[i]);
        // debug(ans[i]);
    }
    cout << minans << endl;
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