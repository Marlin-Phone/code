#include <bits/stdc++.h>
using namespace std;

long long a, b, n;
long long que = 0;
long long day = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n;

    long long week = a * 5 + b * 2;
    long long n0 = n % week;

    day = 7 * (n / week) + 1;

    long long i = 1;
    while (que < n0) {
        if (i <= 5) {
            que += a;
        } else if (i <= 7) {
            que += b;
        } else {
            i = 1;
            que += a;
        }
        i++;
        day++;
    }

    day--;
    cout << day << endl;

    return 0;
}