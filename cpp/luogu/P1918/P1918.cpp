#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define debug(a) cout << #a << ' = ' << a << endl

const int N = 1e5 + 10;
int n;
// vector<int> a(N);
int q;
struct node {
    int val;
    int idx;
} a[N];
int m;

bool cmp(struct node a, struct node b) { return a.val < b.val; }
bool check(int mid) {
    if (a[mid].val <= m) {
        return true;
    }
    return false;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1, cmp);
    cin >> q;
    while (q--) {
        cin >> m;
        int l = 0, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (a[l].val == m) {
            cout << a[l].idx << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}