#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n) {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) { fa[find(x)] = find(y); }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            if (dsu.same(x, y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            dsu.merge(x, y);
        }
    }

    return 0;
}