// https://luogu.com.cn/problem/U535982
#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;

        int AB = 0, BA = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == 'A') {
                    AB++;
                }
                if (s[i] == 'B') {
                    BA++;
                }
            } else {
                if (s[i] == 'A') {
                    BA++;
                }
                if (s[i] == 'B') {
                    AB++;
                }
            }
        }
        cout << min(AB / 2, BA / 2) << endl;
    }

    return 0;
}