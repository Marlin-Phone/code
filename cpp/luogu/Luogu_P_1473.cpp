// https://luogu.com.cn/problem/P1473
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 15;
int n;
int st[N]; // 0为空 1为+ -1为减

bool check(string s) {
    char p = '+';
    int l = s.size();
    int x = 0, y = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == ' ')
            continue;
        if (s[i] >= '0' && s[i] <= '9')
            y = y * 10 + (int)(s[i] - '0');
        if (s[i] == '+') {
            if (p == '+')
                x = x + y;
            if (p == '-')
                x = x - y;
            y = 0;
            p = '+';
        }
        if (s[i] == '-') {
            if (p == '+')
                x = x + y;
            if (p == '-')
                x = x - y;
            y = 0;
            p = '-';
        }
    }
    if (p == '+')
        x = x + y;
    if (p == '-')
        x = x - y;
    if (x == 0)
        return true;
    return false;
}
void dfs(int k, string s) {
    if (k == n) {
        if (check(s)) {
            cout << s << endl;
        }
        return;
    }

    int p = 2 * k - 1; // 计算空格的位置
    dfs(k + 1, s);
    s[p] = '+';
    dfs(k + 1, s);
    s[p] = '-';
    dfs(k + 1, s); // 五行解决字符串处理
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) { // 建串
        s = s + (char)(i + '0') + ' ';
    }
    s.erase(2 * n - 1, 1);
    dfs(1, s);
    // st[n] = 1;
    // st[0] = 1;
    // dfs(1);

    return 0;
}