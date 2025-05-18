#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    int ans1 = pow(2, n);
    int ans2 = pow(n, 3);
    if (ans1 < ans2) {
        cout << "A";
    } else {
        cout << "B";
    }
    return 0;
}