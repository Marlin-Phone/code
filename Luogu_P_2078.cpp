// https://luogu.com.cn/problem/P2078
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e4 + 10;
int T = 1;
int n, m, p, q;
int cnt = 0;

// 并查集-------------------------------
vector<int> arr(N);
void init(int n) {
    cnt = 1;
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
    if (test(a, b) == false) {
        int aHead = findHead(a);
        int bHead = findHead(b);
        arr[aHead] = bHead;
        cnt++;
    }
}
// ------------------------------------

void solve() {
    cin >> n >> m >> p >> q;
    init(n);
    while (p--) {
        int x1, y1;
        cin >> x1 >> y1;
        merge(x1, y1);
    }
    int mincnt = cnt;
    // debug(cnt);
    init(m);
    while (q--) {
        int x1, y1;
        cin >> x1 >> y1;
        x1 = -x1, y1 = -y1;
        merge(x1, y1);
    }
    // debug(cnt);
    mincnt = min(mincnt, cnt);
    cout << mincnt;
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