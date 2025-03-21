#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);
#define endl "\n"

int l, r;

int getyue(int x) { // 得到约数
    for (int i = 1; i <= x; i++) {
        x / i;
    }
}
int main() {
    IOS;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        getyue(i);
    }

    return 0;
}