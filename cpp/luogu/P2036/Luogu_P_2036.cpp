// https://www.luogu.com.cn/problem/P2036
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n';

const int N = 15;
long long sum_s = 1;
long long sum_b = 0;
int n;
long long s[N], b[N];
int st[N]; // 0未知 1选 2不选
long long res = 1e9 + 10;
// s为酸度 总酸度为每一种配料的酸度总乘积
// b为苦度 总苦度为每一种配料的苦度总和

void dfs(int x) {
    if (x > n) {
        bool has_tl = false; // 此处不应该是全局变量 因为每个递归都需要重新计算
        sum_s = 1;
        sum_b = 0;
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                has_tl = true;
                sum_s *= s[i];
                sum_b += b[i];
            }
        }
        // cout << sum_s << " " << sum_b << endl;
        if (has_tl == true) {
            res = min(res, abs(sum_s - sum_b));
        }
        return;
    }

    // cout << "x = " << x << endl;
    if (!st[x]) {
        st[x] = 1; // 选
        dfs(x + 1);
        st[x] = 0; // 回溯

        st[x] = 2; // 不选
        dfs(x + 1);
        st[x] = 0;
    }
}

int main() {
    IOS;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }

    dfs(1);

    cout << res;
    return 0;
}