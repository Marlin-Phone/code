// https://luogu.com.cn/problem/P3405
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 2e5 + 10;
int n;
string state[N];
string name[N];
map<string, int> box;
int ans = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);
        if (a != b) {
            ans += box[a + b];
        }
        box[b + a]++;
    }

    cout << ans;

    return 0;
}