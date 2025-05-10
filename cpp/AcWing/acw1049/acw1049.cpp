#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, T;
int home[N];
int mem[N];
int f[N];

int dfs(int x) {
    if (mem[x])
        return mem[x];

    int sum = 0;
    if (x > n)
        sum = 0;
    else
        sum = max(dfs(x + 1), dfs(x + 2) + home[x]);
    mem[x] = sum;
    return sum;
}
int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> home[i];
        }

        for (int i = n; i >= 1; i--) {
            f[i] = max(f[i + 1], f[i + 2] + home[i]);
        }
    }

    return 0;
}