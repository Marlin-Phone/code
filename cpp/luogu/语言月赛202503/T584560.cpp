#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, S;
    cin >> a >> S;

    b = S / a;

    long long L = 2 * (a + b);

    cout << L;

    return 0;
}