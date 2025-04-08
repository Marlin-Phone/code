#include <bits/stdc++.h>
using namespace std;

int __lcm(int a, int b) { return a * b / __gcd(a, b); }
int main() {

    int ans;
    ans = 45;
    ans ^= 9;
    ans ^= 16;
    cout << ans;

    return 0;
}