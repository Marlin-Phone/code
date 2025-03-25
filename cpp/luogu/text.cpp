#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, k;
int arr[N];
int st[N];

void dfs(int x, int start) {
    if (x > k) {
        for (int i = 1; i <= k; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n - (k - x); i++) {
        arr[x] = i;
        st[i] = 1;
        dfs(x + 1, i + 1);
        arr[x] = 0;
        st[i] = 0;
    }
}
int main() {
    cin >> n >> k;
    dfs(1, 1);

    return 0;
}