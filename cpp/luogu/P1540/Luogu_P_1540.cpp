// https://luogu.com.cn/problem/P1540
// 队列
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1010;
int mem[N];
queue<int> q;
int m, n;
int ans = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (mem[temp] == 1) {
            continue;
        } else {
            if (q.size() == m) {
                mem[q.front()] = 0;
                q.pop();
            }
            q.push(temp);
            mem[temp] = 1;
            ans++;
        }
    }

    cout << ans;

    return 0;
}