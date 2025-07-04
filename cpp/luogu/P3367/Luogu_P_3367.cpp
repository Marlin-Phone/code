// https://luogu.com.cn/problem/P3367
// 并查集 路径压缩
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n, m;

class DSU { // disjoined set union
  private:
    vector<int> arr;

  public:
    DSU(int n) {
        arr = vector<int>(n + 10);
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
        }
    }
    void merge(int a, int b) {
        int aHead = findHead(a);
        int bHead = findHead(b);
        arr[aHead] = bHead;
    }
    int findHead(int x) {
        if (arr[x] != x) {
            arr[x] = findHead(arr[x]); // 路径压缩
        }
        return arr[x];
    }
    bool test(int a, int b) { return findHead(a) == findHead(b); }
};

void solve() {
    cin >> n >> m;
    DSU dsu = DSU(n + 10);
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        switch (z) {
        case 1: {
            dsu.merge(x, y);
            break;
        }
        case 2: {
            if (dsu.test(x, y)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
            break;
        }
        }
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