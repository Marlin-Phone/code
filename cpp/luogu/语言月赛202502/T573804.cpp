#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

long long n;

int main() {
    IOS;
    long long L, R; // n 个元素, L 为最小值, R 为最大值
    cin >> n >> L >> R;

    cout << L << " ";
    for (int i = 2; i <= n; i++) {
        cout << "0" << " ";
    }

    return 0;
}