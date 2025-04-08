// https://luogu.com.cn/problem/P1473
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 15;
int n;
int st[N]; // 0为空 1为+ -1为减

void dfs(int x) {
    if (x > n - 1) {
        int ans = 1;
        for (int i = 1; i <= n - 1; i++) {
            if (st[i] == -1) {
                if (st[i + 1] != 0)
                    ans -= i + 1;

            } else if (st[i] == 0) {
                int num = i + 1;
                num *= 10;
                num += i + 2;
                if (st[i - 1] == 1) {
                    ans += num;
                } else if (st[i - 1] == -1) {
                    ans -= num;
                } else if (st[i - 1] == 0) {
                    return;
                }
            } else if (st[i] == 1) {
                if (st[i + 1] != 0)
                    ans += i + 1;
            }
            // cout << "ans = " << ans << " i = " << i << endl;
        }
        if (ans == 0) {
            for (int i = 1; i <= n; i++) {
                cout << i;
                if (st[i] == -1) {
                    cout << "-";
                } else if (st[i] == 0) {
                    cout << " ";
                } else if (st[i] == 1) {
                    cout << "+";
                }
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i >= -1; i--) {
        st[x] = i;
        dfs(x + 1);
        st[x] = 0; // 回溯
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    // st[n] = 1;
    st[0] = 1;
    dfs(1);

    return 0;
}