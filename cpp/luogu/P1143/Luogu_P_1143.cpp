#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n;
string str;
int m;
int nums[N];

int n2ten(string str) {
    int res = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        int temp = 0;
        if ('0' <= str[i] && str[i] <= '9') {
            temp += str[i] - '0';
        } else {
            temp += 10 + (str[i] - 'A');
        }
        temp *= pow(n, str.size() - 1 - i);
        res += temp;
    }
    return res;
}
string ten2m(int num) {
    string res;

    while (num > 0) {
        int temp = num % m;
        num /= m;
        if (temp < 10) {
            res.push_back(temp + '0');
        } else {
            res.push_back(temp - 10 + 'A');
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    cin >> n;
    cin >> str;
    cin >> m;
    int num = n2ten(str);
    // cout << num << endl;
    cout << ten2m(num) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}