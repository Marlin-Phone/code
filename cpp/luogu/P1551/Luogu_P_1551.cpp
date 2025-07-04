// https://luogu.com.cn/problem/P1551
// 并查集
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e3 + 10;
int T = 1;
int n, m, p;

// 并查集---------------------
vector<int> arr(N);
void init(int n) {
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
}
int findHead(int x) {
    if (arr[x] != x) {
        arr[x] = findHead(arr[x]);
    }
    return arr[x];
}
bool test(int a, int b) { return findHead(a) == findHead(b); }
void merge(int a, int b) {
    int aHead = findHead(a);
    int bHead = findHead(b);
    arr[aHead] = bHead;
}
// --------------------------
void solve() {
    cin >> n >> m >> p;
    init(n);
    for (int i = 1; i <= m; i++) {
        int mi, mj;
        cin >> mi >> mj;
        merge(mi, mj);
    }
    while (p--) {
        int pi, pj;
        cin >> pi >> pj;
        if (test(pi, pj)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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