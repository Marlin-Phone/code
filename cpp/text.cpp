#include <bits/stdc++.h>
using namespace std;

int jia, yi;
int n;
int jhan, jh, yhan, yh;
int cnta = 0, cntb = 0;

void check() {
    if (jh == jhan + yhan && yh != jhan + yhan) {
        cnta++;
        jia--;
    } else if (yh == jhan + yhan && jh != jhan + yhan) {
        cntb++;
        yi--;
    }
}
int main() {
    cin >> jia >> yi;
    cin >> n;
    while (n--) {
        cin >> jhan >> jh >> yhan >> yh;
        check();
        if (jia < 0 || yi < 0) {
            break;
        }
    }

    // cout << "cnta = " << cnta << endl;
    // cout << "cntb = " << cntb << endl;
    if (jia < 0) {
        cout << "A" << endl;
        cout << cntb;
    } else {
        cout << "B" << endl;
        cout << cnta;
    }

    return 0;
}