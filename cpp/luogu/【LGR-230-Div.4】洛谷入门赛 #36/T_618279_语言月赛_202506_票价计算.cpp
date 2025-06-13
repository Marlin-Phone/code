// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e5 + 10;
int T = 1;
int n;
int a1, b1, a2, b2, a3, b3, c;
int maxb = 0;
int cost;
struct node {
    int a, b;
} node[N];
int maxidx;

void solve() {
    // 1
    for (int i = 1; i <= 3; i++) {
        cin >> node[i].a >> node[i].b;
        if (node[i].b > maxb) {
            maxb = node[i].b;
            maxidx = i;
        }
    }
    cin >> c;
    // cout << maxidx << endl;

    int ansidx = 1;
    int mincost = 1e9;
    for (int i = 1; i <= 3; i++) {
        int cost = node[i].a - (node[maxidx].b - node[i].b) * c;
        if (cost < mincost) {
            mincost = cost;
            ansidx = i;
        }
    }
    cout << ansidx << " " << mincost;
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