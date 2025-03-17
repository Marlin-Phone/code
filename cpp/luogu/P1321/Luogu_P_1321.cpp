#include <bits/stdc++.h>
using namespace std;

int boy, girl = 0;
string str;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'b' || str[i + 1] == 'o' || str[i + 2] == 'y') {
            boy++;
        }
        if (str[i] == 'g' || str[i + 1] == 'i' || str[i + 2] == 'r' ||
            str[i + 3] == 'l') {
            girl++;
        }
    }

    cout << boy << endl;
    cout << girl << endl;

    return 0;
}