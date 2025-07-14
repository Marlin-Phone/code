#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int x1, y1, x2, y2;

    cin >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    // 判断两个起点的 x + y 的奇偶性是否相同
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}