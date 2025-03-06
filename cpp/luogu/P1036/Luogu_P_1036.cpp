// https://www.luogu.com.cn/problem/P1036
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

const int N = 30;
int n, k;
int num[N];
int arr[N];
int ans = 0;
int total = 0;

bool isprime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int x, int start) {
    if (n - start + 1 < k - x + 1) // 剪枝
        return;
    if (x > k) {
        ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += arr[i];
        }
        if (isprime(ans)) {
            total++;
        }
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[x] = num[i];
        dfs(x + 1, i + 1);
        arr[x] = 0;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    dfs(1, 1);
    cout << total;
    return 0;
}