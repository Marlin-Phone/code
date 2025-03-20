// https://www.luogu.com.cn/problem/P1597
#include <bits/stdc++.h>
using namespace std;

char str[3];
char str_[3];
string stra, strb, strc;
int a, b, c;

int main() {
    int i = 0;
    while (scanf("%c:=%c;", &str[i], &str_[i]) == 2) {
        if (str_[i] >= '0' && str_[i] <= '9') {
            if (str[i] == 'a') {
                a = str_[i] - '0';
            } else if (str[i] == 'b') {
                b = str_[i] - '0';
            } else if (str[i] == 'c') {
                c = str_[i] - '0';
            } else {
                if (str[i] == 'a') {
                    a = 0;
                }
                if (str[i] == 'b') {
                    b = 0;
                }
                if (str[i] == 'c') {
                    c = 0;
                }
            }
        } else {
            if (str[i] == 'a') {
                if (str_[i] == 'a') {
                    a = a;
                } else if (str_[i] == 'b') {
                    a = b;
                } else if (str_[i] == 'c') {
                    a = c;
                }
            } else if (str[i] == 'b') {
                if (str_[i] == 'a') {
                    b = a;
                } else if (str_[i] == 'b') {
                    b = b;
                } else if (str_[i] == 'c') {
                    b = c;
                }
            } else if (str[i] == 'c') {
                if (str_[i] == 'a') {
                    c = a;
                } else if (str_[i] == 'b') {
                    c = b;
                } else if (str_[i] == 'c') {
                    c = c;
                }
            }
        }
        i++;
    }
    // for (int i = 0; i < 3; i++) {
    //     cout << str[i] << " " << str_[i] << endl;
    // }
    cout << a << " " << b << " " << c << endl;
    return 0;
}