// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;

string getBinary(int x) {
    string res = "";
    while (x != 0) {
        res += to_string(x % 2);
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int add(int a, int b) {
    int ans = a;     // a和b无进位相加的结果
    while (b != 0) { // 进位信息不为0时循环
        ans = a ^ b;
        b = (a & b) << 1; // a和b相加时的进位信息
        a = ans;
    }
    return ans;
}
int subtract(int a, int b) { return add(a, add(~b, 1)); }
int multiply(unsigned int a, unsigned int b) {
    unsigned int ans = 0;
    while (b != 0) {
        if ((b & 1) != 0) {
            ans = add(ans, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return ans;
}
void solve() {
    // cin >> n;
    int a = 0b001011;
    int b = 0b001110;
    int c = add(a, b);
    int d = subtract(b, a);
    cout << getBinary(c) << endl;
    cout << getBinary(d) << endl;

    cout << getBinary(a + b) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}