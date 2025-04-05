#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    if (a > b + c) {
        cout << "l";
    } else if (b > a + c) {
        cout << "q";
    } else if (c > a + b) {
        cout << "b";
    } else {
        cout << -1;
    }

    return 0;
}