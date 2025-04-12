// https://luogu.com.cn/problem/P12133
// 思维 剪枝
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int T;
int A, B, C, K;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> A >> B >> C >> K;
        for (int i = 1; i <= K; i++) {
            int Ap = (B + C) / 2;
            int Bp = (A + C) / 2;
            int Cp = (A + B) / 2;
            A = Ap;
            B = Bp;
            C = Cp;
            if (Ap == Bp && Bp == Cp && Cp == Ap) {
                break;
            }
        }
        cout << A << " " << B << " " << C << endl;
    }

    return 0;
}