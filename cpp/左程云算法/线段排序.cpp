// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;
vector<pair<int, int>> line;
priority_queue<int, vector<int>, less<int>> heap;
// struct heap_cmp {
//     bool operator()(const int &a, const int &b) const { return a > b; }
// };

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }

void solve() {
    cin >> n;
    line.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
    }
    sort(line.begin(), line.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (heap.size() > 0 && heap.top() <= line[i].first) {
            heap.pop();
        }
        heap.push(line[i].second);

        ans = max(ans, (int)heap.size());
    }
    cout << ans << endl;
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