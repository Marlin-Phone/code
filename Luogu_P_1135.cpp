#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    \    
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n";

const int N = 210;
int nums[N];
int res = 1e9;
int n, A, B;
bool st[N]; // 存每层楼是否走过

void dfs(int x, int cnt) { // 当前在x楼, 按了cnt次按钮
    if (x < 0 || x > n)
        return;
    if (cnt >= res) {
        return;
    }
    if (x == B) {
        res = min(res, cnt);
    }

    // 上
    if (x + nums[x] <= n && !st[x + nums[x]]) {
        // cout << x << " " << x + nums[x] << endl;
        st[x + nums[x]] = true;
        dfs(x + nums[x], cnt + 1);
        st[x + nums[x]] = false; // 回溯
    }

    // 下
    if (x - nums[x] > 0 && !st[x - nums[x]]) {
        st[x - nums[x]] = true;
        dfs(x - nums[x], cnt + 1);
        st[x - nums[x]] = false; // 回溯
    }
}
int main() {
    IOS;

    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    dfs(A, 0);
    if (res == 1e9)
        res = -1;
    cout << res;

    return 0;
}