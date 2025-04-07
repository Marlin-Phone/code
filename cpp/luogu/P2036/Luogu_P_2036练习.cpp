// https://luogu.com.cn/problem/P2036
// 指数型枚举(选或不选)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 20;
int n;
int s[N]; // 酸度 乘积
int b[N]; // 苦度 总和
int minnum = 1e9;
int st[N];

void dfs(int x) {
    if (x > n) {
        int flag = 0;
        int ts = 1;
        int sumb = 0;
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                flag = 1;
                ts *= s[i];
                sumb += b[i];
            }
        }
        // cout << "abs(ts - sumb) = " << abs(ts - sumb) << endl;
        if (flag == 1) {
            minnum = min(abs(ts - sumb), minnum);
        }
        return;
    }

    st[x] = 1; // 选
    dfs(x + 1);
    st[x] = 1; // 回溯

    st[x] = 0; // 不选
    dfs(x + 1);
    st[x] = 0; // 回溯
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }

    dfs(1);

    cout << minnum;

    return 0;
}