#include <bits/stdc++.h>
using namespace std;

string s;
int T;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> s;
        if ('0' <= s[0] && s[0] <= '9') {
            cout << "https://www.luogu.com.cn/problem/" << "P" << s << endl;
        } else {
            cout << "https://www.luogu.com.cn/problem/" << s << endl;
        }
    }

    return 0;
}