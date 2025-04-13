// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e5 + 10;
int n;
int A[N];
int tempA[N];
int st[N];
int ans = 0;

void dfs(int x) {
    if (x > n - 1) {
        tempA[1] = A[1];
        int tempans = tempA[1];
        for (int i = 1; i <= n - 1; i++) {
            tempA[i + 1] = A[i + 1];
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << tempA[i] << " ";
        // }
        // cout << endl;

        for (int i = 1; i <= n - 1; i++) {
            if (st[i] == 0) {
                tempA[i] ^= tempA[i + 1];
                tempA[i + 1] = 0;
                st[i] == 1;
                // cout << "tempA[i] = " << tempA[i] << endl;
            }
            111
        }

        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                tempans += tempA[i + 1];
            } else if (st[i] == -1) {
                tempans -= tempA[i + 1];
            } else {
                tempans += tempA[i + 1];
            }
        }
        cout << "tempans = " << tempans << endl;
        ans += tempans;

        return;
    }

    st[x] = 0;
    dfs(x + 1);
    st[x] = 1;
    dfs(x + 1);
    st[x] = -1;
    dfs(x + 1);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    dfs(1);

    cout << ans;

    return 0;
}