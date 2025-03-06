// https://www.luogu.com.cn/problem/P2089
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 5010;
int n;
int arr[N];
bool st[N];
int sum = 0;
int ans = 0;
int ansnum[60000][15];

void dfs(int x) {
    if (n < 10 || n > 30) {
        cout << 0;
        exit(0);
    }

    if (sum > n) {
        return;
    }
    if (x > 10) {
        if (sum == n) {
            ans++;
            for (int i = 1; i <= 10; i++) {
                ansnum[ans][i] = arr[i];
            }
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (!st[x]) {
            arr[x] = i;
            sum = sum + i;
            st[x] = true;
            dfs(x + 1);
            arr[x] = 0;
            sum = sum - i;
            st[x] = false;
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << ansnum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}