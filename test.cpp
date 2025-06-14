#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(a) cout << #a << " = " << a << endl;

const int N = 1e5 + 10;
int num[N];
int n;
int st[N];

void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                cout << num[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    st[x] = 1;
    dfs(x + 1);

    st[x] = 0;
    dfs(x + 1);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    dfs(1);

    return;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}
