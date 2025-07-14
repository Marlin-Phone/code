#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k;
    cin >> k;
    long long n = k + 1;

    if (n < 2) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }

    long long d = -1;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            d = i;
            break;
        }
    }

    if (d == -1) {
        cout << -1 << endl;
    } else {
        long long other = n / d;
        long long a = d - 1;
        long long b = other - 1;
        long long p = a + b;
        long long q = a * b;
        cout << p << " " << q << endl;
    }

    return 0;
}