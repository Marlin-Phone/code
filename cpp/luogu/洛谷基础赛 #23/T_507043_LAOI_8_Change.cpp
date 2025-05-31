// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n;
int A_B[N];
int A[N], B[N];
map<int, int> mp;
vector<int> vec;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
            mp[B[i]] = i;
        }

        int g = 0; // 计算最大约束g
        for (int i = 1; i <= n; i++) {
            int idx_AinB = mp[A[i]];
            int d = abs(idx_AinB - i);
            if (d != 0) {
                if (g == 0) {
                    g = abs(d);
                } else {
                    g = __gcd(g, abs(d));
                }
            }
        }

        // 求解有效约数
        if (g == 0) {

        } else {
            for (int i = 1; i * i <= g; i++) {
                if (g % i == 0) {
                    if (i <= n - 1) {
                        vec.push_back(i); // i是约数
                    }
                    int j = g / i;
                    if (j != i && j <= n - 1) {
                        vec.push_back(j); // j是互补约数
                    }
                }
            }
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << endl;
        }
    }
    return 0;
}