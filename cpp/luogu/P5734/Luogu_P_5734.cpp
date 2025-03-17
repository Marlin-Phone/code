#include <bits/stdc++.h>
using namespace std;

int q;
string str, str1;
int num;

int main() {
    cin >> q;
    cin >> str;
    while (q--) {
        cin >> num;
        switch (num) {
        case 1: {
            cin >> str1;
            str = str + str1;
            cout << str << endl;
            break;
        }
        case 2: {
            int i, length;
            cin >> i >> length;
            str = str.substr(i, length);
            cout << str << endl;
            break;
        }
        case 3: {
            int i;
            cin >> i >> str1;
            str.insert(i, str1);
            cout << str << endl;
            break;
        }
        case 4: {
            cin >> str1;
            if (str.find(str1) != string::npos) {
                cout << str.find(str1) << endl;
            } else {
                cout << -1 << endl;
            }
        }
        }
    }

    return 0;
}