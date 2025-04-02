// https://www.luogu.com.cn/problem/P1090
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4 + 10;
int n;
int a[N];
priority_queue<int, vector<int>, greater<int>> pq;
int ans = 0;
int weight = 0;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }

    // while (pq.size() != 0) {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }

    while (pq.size() > 1) { // 边界
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        weight = a + b;
        ans += weight;
        pq.push(weight);
    }

    cout << ans;

    return 0;
}