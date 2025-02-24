// https://www.luogu.com.cn/problem/P1135
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 210;
int nums[N];
int res = 1e9;
int n, A, B;
bool st[N]; // 存每层楼是否走过
queue<pair<int, int>> q;
int dx[2] = {1, -1};

int bfs(int x, int cnt) { // 当前在x楼, 按了cnt次按钮
    q.push({x, cnt});
    st[x] = true;
    if (x == B)
        return 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int a = t.first + dx[i] * nums[t.first];
            int b = t.second + 1;
            if (a > n || a < 1)
                continue;
            if (st[a] == true)
                continue;

            st[a] = true;
            if (a == B)
                return b;
            q.push({a, b});
        }
    }
    return -1;
}
// dfs 会TLE
// void dfs(int x, int cnt) { // 当前在x楼, 按了cnt次按钮
//     if (x < 0 || x > n)
//         return;
//     if (cnt >= res) {
//         return;
//     }
//     if (x == B) {
//         res = min(res, cnt);
//     }

//     // 上
//     if (x + nums[x] <= n && !st[x + nums[x]]) {
//         // cout << x << " " << x + nums[x] << endl;
//         st[x + nums[x]] = true;
//         dfs(x + nums[x], cnt + 1);
//         st[x + nums[x]] = false; // 回溯
//     }

//     // 下
//     if (x - nums[x] > 0 && !st[x - nums[x]]) {
//         st[x - nums[x]] = true;
//         dfs(x - nums[x], cnt + 1);
//         st[x - nums[x]] = false; // 回溯
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    // dfs(A, 0);
    cout << bfs(A, 0) << endl;
    // if (res == 1e9)
    //     res = -1;
    // cout << res;

    return 0;
}