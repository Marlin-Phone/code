// https://www.luogu.com.cn/problem/P1319
#include <bits/stdc++.h>
using namespace std;

int n;
int temp;
int flag = 0;
int thisline = 0;

int main() {
    cin >> n;
    while (cin >> temp) {
        if (flag == 0) {
            while (temp--) {
                cout << "0";
                thisline++;
                if (thisline == n) {
                    cout << endl;
                    thisline = 0;
                }
            }
            flag = 1;
        } else {
            while (temp--) {
                cout << "1";
                thisline++;
                if (thisline == n) {
                    cout << endl;
                    thisline = 0;
                }
            }
            flag = 0;
        }
    }

    return 0;
}