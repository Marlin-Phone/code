// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

// const int N =
int T = 1;
int n, m, c, k;

void solve() {
    string s;
    getline(cin, s);
    string ans = "";
    size_t i = 0;
    while (i < s.length()) {
        if (s[i] == '(') {
            size_t pos1 = s.find(')', i);
            if (pos1 == string::npos)
                break;
            string content = s.substr(i + 1, pos1 - i - 1);

            size_t pos2 = s.find('[', pos1);
            if (pos2 == string::npos)
                break;
            size_t pos3 = s.find(']', pos2);
            if (pos3 == string::npos)
                break;
            string times_str = s.substr(pos2 + 1, pos3 - pos2 - 1);
            int times = stoi(times_str);

            for (int j = 0; j < times; j++) {
                ans += content;
            }

            i = pos3 + 1;
        } else {
            i++;
        }
    }
    cout << '*' << ans << '*' << endl;
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