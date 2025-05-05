#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(int idx, int v) {
    if (idx == n) {
        // cout << v << endl;
        for (int i = 0; i < idx; i++) {
            if (v >> i & 1) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
        return;
    }

    dfs(idx + 1, v);
    dfs(idx + 1, v + (1 << (n - idx - 1)));
}
int main() {
    cin >> n;

    dfs(0, 0);

    return 0;
}