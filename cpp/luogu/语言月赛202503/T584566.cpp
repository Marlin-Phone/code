#include <bits/stdc++.h>
using namespace std;

int n; // 扑克牌有2n张
string str;

int main() {
    cin >> n;

    int i = 0;
    while (str[i]) {
        char ch = getchar();
        if (str[i] == ',') {
            i--;
        } else {
            str[i] = ch;
        }
        i++;
    }
    return 0;
}