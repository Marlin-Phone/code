#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 1e4 + 10;
int n, m;
int num[N];
int st[N];
int arr[N];
int ans = 0;

void dfs(int x) {
    if (x > n) {
        if (ans == m) {
            for (int i = 1; i <= n; i++) {
                cout << arr[i] << " ";
            }
            exit(0);
        }
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!ans) {
            i = num[x];
        }
        if (!st[i]) {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    dfs(1);

    return 0;
}