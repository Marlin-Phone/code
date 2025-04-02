// https://www.luogu.com.cn/problem/P1803
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
int n;
struct node {
    int bet, edt;
    int tim;
} node[N];
bool st[N];
int ans = 0;

bool check(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (st[i] == true) {
            return false;
        }
    }

    for (int i = l; i <= r; i++) {
        st[i] = true;
    }
    return true;
}
bool cmp(struct node &a, struct node &b) { return a.edt < b.edt; }
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].bet >> node[i].edt;
        node[i].tim = node[i].edt - node[i].bet;
    }

    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) { // 遍历每个时间段
        if (check(node[i].bet, node[i].edt - 1)) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}