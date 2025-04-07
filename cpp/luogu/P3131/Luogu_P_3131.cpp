// https://luogu.com.cn/problem/P3131
// 前缀和 前缀和余数的性质 枚举
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 5e4 + 10;
int n;
int id[N];
int Sid[N];
int ans = 0;
int first[7];
int last[7];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> id[i];
        Sid[i] = (Sid[i - 1] + id[i]) % 7; // 前缀和取模数组
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << Sid[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i <= 6; i++) {     // 枚举余数
        for (int j = 0; j <= n; j++) { // 枚举前缀和取模数组
            if (Sid[j] == i) {
                if (first[i] == 0) {
                    first[i] = j;
                }
                last[i] = j;
            }
        }
    }

    first[0] = 0;
    for (int i = 0; i <= 6; i++) {
        // cout << "i = " << i << " ans = " << ans << endl;
        ans = max(last[i] - first[i], ans);
    }

    cout << ans;

    return 0;
}