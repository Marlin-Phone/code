// https://www.luogu.com.cn/problem/P1553
#include <bits/stdc++.h>
using namespace std;

string s;

string reverse(string s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            cnt++;
        }
    }
    if (cnt == s.length() && s.length() != 0) {
        return "0";
    }

    char temp;
    int l = 0, r = s.length() - 1;
    while (l < r) {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }

    int fis0 = 1;
    int j = 0;
    string s0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' && fis0 == 1) {
            continue;
        } else {
            fis0 = 0;
            s0 += s[i];
        }
    }
    return s0;
}
int main() {
    cin >> s;
    int pos_point = s.find('.');
    int pos_slash = s.find('/');
    int pos_persent = s.find('%');
    if (pos_point != -1) { // .
        cout << reverse(s.substr(0, pos_point));
        cout << '.';

        string s_temp = s.substr(pos_point + 1, s.length() - pos_point - 1);

        int l = 0, r = s_temp.length() - 1;
        while (l < r) {
            char temp = s_temp[l];
            s_temp[l] = s_temp[r];
            s_temp[r] = temp;
            l++;
            r--;
        }

        int s_templl = stoll(s_temp);

        while (s_templl % 10 == 0 && s_templl != 0) {
            s_templl /= 10;
        }
        cout << s_templl;
    } else if (pos_slash != -1) {
        cout << reverse(s.substr(0, pos_slash));

        cout << '/';

        cout << reverse(s.substr(pos_slash + 1, s.length() - pos_slash - 1));

    } else if (pos_persent != -1) { // %
        string s_left = s.substr(0, pos_persent);
        string s_right =
            s.substr(pos_persent + 1, s.length() - 1 - pos_persent);
        cout << reverse(s_left) << '%' << reverse(s_right);
    } else { //
        cout << reverse(s);
    }

    return 0;
}