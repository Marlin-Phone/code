// https://www.luogu.com.cn/problem/P1042
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
char ch;
string str;
int scorea, scoreb;

int main() {
    while (cin >> ch) {
        if (ch == 'E') {
            str += ch;
            break;
        }
        str += ch;
    }

    for (int i = 0, i0 = 0; i < str.size(); i++, i0++) {
        if (str[i] == 'W') {
            scorea++;
        }
        if (str[i] == 'L') {
            scoreb++;
        }
        if ((scorea >= 11 || scoreb >= 11) && abs(scorea - scoreb) >= 2 ||
            str[i] == 'E') {
            cout << scorea << ":" << scoreb << endl;
            i0 = 0;
            scorea = scoreb = 0;
        }
    }

    cout << endl;

    for (int i = 0, i0 = 0; i < str.size(); i++, i0++) {
        if ((scorea >= 21 || scoreb >= 21) && abs(scorea - scoreb) >= 2 ||
            str[i] == 'E') {
            cout << scorea << ":" << scoreb << endl;
            i0 = 0;
            scorea = scoreb = 0;
        }
        if (str[i] == 'W') {
            scorea++;
        }
        if (str[i] == 'L') {
            scoreb++;
        }
    }

    return 0;
}