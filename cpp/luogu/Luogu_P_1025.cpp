#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 210;
int n, k;
int arr[N];
bool st[N];
int ans = 0;

void dfs(int x, int start, int nowSum) {
    if (x > k) {
        if (nowSum == n) {
            ans++;
        }
        return;
    }

    for (int i = start; nowSum + i * (k - x + 1) <= n; i++) {
        if (st[x] == false) {
            st[x] = true;
            arr[x] = i;
            dfs(x + 1, i, nowSum + i);
            st[x] = false;
            arr[x] = 0;
        }
    }
}
int main() {
    IOS;

    cin >> n >> k;

    dfs(1, 1, 0);

    cout << ans << endl;

    return 0;
}