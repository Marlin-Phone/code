#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b && a > c) {
        cout << "LeftToRight" << endl;
    } else if (b > a && b > c) {
        cout << "RightToLeft" << endl;
    } else if (a == b) {
        cout << "None" << endl;
    } else if (c >= a && c >= b) {
        cout << "None" << endl;
    }

    return 0;
}