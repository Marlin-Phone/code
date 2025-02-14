#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

int main() {
    IOS;
    long long Ve, Vm, Vt;
    long long e, m, t;
    long long ans0;

    cin >> Ve >> Vm >> Vt;
    cin >> e >> m >> t;

    ans0 = e * Ve + m * Vm;
    long long ans1 = ans0 / Vt;
    long long ans2 = ans1 / t + 1;

    cout << ans2 << endl;

    return 0;
}