#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

int main() {
    long long n, x, y;
    long long temp;
    // n 是车站数, x 是起始点, y 是终点
    cin >> n >> x >> y;
    // 1 - 10: 1 9

    temp = x - y;
    temp = abs(temp);

    if (n * 1.0 / 2 > temp) {
        cout << "Clockwise Loop" << endl;
    } else if (n * 1.0 / 2 < temp) {
        cout << "Counter-clockwise Loop" << endl;
    } else {
        cout << "\"Wonderful\"" << endl;
    }

    return 0;
}