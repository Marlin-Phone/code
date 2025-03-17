// https://www.luogu.com.cn/problem/P1125
#include <bits/stdc++.h>
using namespace std;

string str;
int word[26];
int minn = 1e9;
int maxn = -1;

bool isprime(int x) {
    if (x < 2) {
        return false;
    } else if (x == 2) {
        return true;
    } else {
        for (int i = 2; i <= sqrt(x) + 1; i++) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        word[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (word[i] != 0) {
            minn = min(minn, word[i]);
        }
        maxn = max(maxn, word[i]);
    }

    // cout << "minn = " << minn << endl;
    // cout << "maxn = " << maxn << endl;

    if (isprime(maxn - minn)) {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0;
    }

    return 0;
}