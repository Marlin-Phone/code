#include <bits/stdc++.h>
using namespace std;

class Solve {
    int f1(string &s, int i) {
        if (i == s.size()) {
            return 1;
        }
        int ans;
        if (s[i] == '0') {
            ans = 0;
        } else {
            ans = f1(s, i + 1);
            if (i + 1 < s.size() &&
                ((s[i] - '0') * 10 + s[i + 1] - '0') <= 26) {
                ans += f1(s, i + 2);
            }
        }
        return ans;
    }
};

int main() { return; }