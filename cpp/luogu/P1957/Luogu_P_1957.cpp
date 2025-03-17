// https://www.luogu.com.cn/problem/P1957
#include <bits/stdc++.h>
using namespace std;

int p;
char ch;
string str;
int a, b;

int getwei(int x) {
    int res = 0;
    if (x <= 0) {
        res++;
    }
    while (x) {
        x /= 10;
        res++;
    }
    // cout << "res = " << res << endl;
    return res;
}
int main() {
    cin >> p;
    while (p--) {
        cin >> str;
        if ('a' <= str[0] && str[0] <= 'c') {
            ch = str[0];
            cin >> a >> b;
            int cnt = getwei(a) + getwei(b) + 2;
            // cout << "cnt = " << cnt << endl;
            switch (ch) {
            case 'a': {
                cout << a << "+" << b << "=" << a + b << endl;
                cnt += getwei(a + b);
                break;
            }
            case 'b': {
                cout << a << "-" << b << "=" << a - b << endl;
                cnt += getwei(a - b);
                break;
            }
            case 'c': {
                cout << a << "*" << b << "=" << a * b << endl;
                cnt += getwei(a * b);
                break;
            }
            }
            cout << cnt << endl;
        } else {
            a = stoi(str);
            cin >> b;
            int cnt = getwei(a) + getwei(b) + 2;
            switch (ch) {
            case 'a': {
                cout << a << "+" << b << "=" << a + b << endl;
                cnt += getwei(a + b);
                break;
            }
            case 'b': {
                cout << a << "-" << b << "=" << a - b << endl;
                cnt += getwei(a - b);
                break;
            }
            case 'c': {
                cout << a << "*" << b << "=" << a * b << endl;
                cnt += getwei(a * b);
                break;
            }
            }
            cout << cnt << endl;
        }
    }

    return 0;
}