// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n, k;
struct node {
    int val, idx;
} a[N], b[N];
bool cmp(struct node &a, struct node &b) { return a.val < b.val; }
multiset<int> even_set;
multiset<int> odd_set;
priority_queue<int> pq;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (auto it : a) {
        even_set.insert(it);
        odd_set.insert(it ^ k);
    }

    for (int m = 1; m <= n - 1; m++) {
        if (m % 2 == 1) {
            int v_min = *odd_set.begin();
            int x = v_min ^ k;
            even_set.erase(even_set.find(x));
            odd_set.erase(odd_set.begin());
        } else {
            int v_min = *even_set.begin();
            int y = v_min ^ k;
            even_set.erase(even_set.begin());
            odd_set.erase(odd_set.find(y));
        }
    }

    if (n % 2 == 1) {
        cout << *even_set.begin() << endl;
    } else {
        cout << *odd_set.begin() << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].val << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].idx << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << b[i].idx << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << b[i].val << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].val << " ";
    // }
    // cout << endl;
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