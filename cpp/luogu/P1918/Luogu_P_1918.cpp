// https://luogu.com.cn/problem/P1918
// 二分 | 结构体排序
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e5 + 10;
int n;
int Q;
int m;
struct node {
    int a;
    int idx;
} node[N];

bool cmp(struct node &a, struct node &b) { return a.a < b.a; }
bool check(int mid) {
    if (node[mid].a <= m) {
        return true;
    } else {
        return false;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].a;
        node[i].idx = i;
    }
    sort(node + 1, node + 1 + n, cmp);
    // for (int i = 1; i <= n; i++) {
    //     cout << node[i].a << " ";
    // }
    cin >> Q;
    while (Q--) {
        cin >> m;

        int l = 0, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
                // cout << "l = " << l << endl;
            } else {
                r = mid;
                // cout << "r = " << r << endl;
            }
        }
        if (node[l].a == m) {
            cout << node[l].idx << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}