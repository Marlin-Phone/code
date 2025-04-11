// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
int a, e, c; // 角块 棱块 转轴
// 8 12 1
int suma, sume, sumc;
int numa, nume, numc;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> e >> c;
        a = 8 - a;
        e = 12 - e;
        c = 1 - c;
        suma += a;
        sume += e;
        sumc += c;
    }

    numa = suma / 8;
    nume = sume / 12;
    numc = sumc / 1;
    // cout << "text " << endl;
    cout << min(min(numa, numc), nume);

    return 0;
}