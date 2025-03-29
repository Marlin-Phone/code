// 错误,打表观察得到45
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 20;
int temp;
long long ans = 0;
map<int, int> mp;

int getnum(int num) {
    while (num > 0) {
        temp = num % 10;
        num /= 10;
    }
    // cout << temp << endl;
    return temp;
}
signed main() {
    for (int i = 1; i <= 27;
         i++) { // n <= 27 时(5^28就溢出了)答案都为45,推测为45
        // cout << "2^" << i << " = " << pow(2, i) << endl;
        // cout << "5^" << i << " = " << pow(5, i) << endl;
        int p = getnum(pow(2, i));
        int q = getnum(pow(5, i));
        int preans = p * q;
        if (mp[preans] == 1) {
            continue;
        } else {
            mp[preans] = 1;
            ans += preans;
        }
    }

    // cout << log10(5) << endl;
    cout << ans;

    return 0;
}