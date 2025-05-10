// https://ac.nowcoder.com/acm/contest/90960/D
#include <bits/stdc++.h>
using namespace std;

int a, b, x, y;
int mincnt = 1e9;

int main() {
    cin >> a >> b >> x >> y;
    for (int i = 1; i <= 20; i++) {
        int cnt = i;
        int a1 = a - i * y;
        int b1 = b - i * y;
        while (a1 > 0) {
            a1 -= x;
            cnt++;
        }
        while (b1 > 0) {
            b1 -= x;
            cnt++;
        }
        mincnt = min(mincnt, cnt);
    }

    cout << mincnt;

    return 0;
}