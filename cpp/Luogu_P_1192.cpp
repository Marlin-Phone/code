#include <bits/stdc++.h>
using namespace std;

#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int n, k;
int memo[N]; // 缓存数组

int dfs(int current) {
    if (current == n)
        return 1;
    if (current > n)
        return 0;
    if (memo[current] != -1)
        return memo[current]; // 直接返回缓存结果

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum = (sum + dfs(current + i)) % MOD;
    }
    memo[current] = sum; // 存储结果
    return sum;
}

int main() {
    IOS;
    cin >> n >> k;
    memset(memo, -1, sizeof(memo)); // 初始化缓存数组
    cout << dfs(0) << endl;
    return 0;
}