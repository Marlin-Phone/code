// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 5010;
int n;
struct active {
    char type;   // O学校 C社团 P个人
    string date; // YYYYMMDD
    char tim;    // M上午 A下午 E晚上
} act[N];
map<string, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> act[i].type >> act[i].date >> act[i].tim;
    }

    return 0;
}