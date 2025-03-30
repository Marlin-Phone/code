#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    getline(cin, str);

    for (int i = 0; i < str.size() - 1; i++) {
        switch (str[i]) {
        case '@': {
            if (str[i + 1] == 'a' || str[i + 1] == '1' || str[i + 1] == '$') {
                cout << "No";
                return 0;
            }
        }
        case ',': {
            int flag = 0;
            for (int j = i; j >= 0 && j < str.size(); j++) {
                if (str[j] == '@') {
                    break;
                }
                if (str[j] == '_') {
                    flag = 1;
                }
                if (str[j] == 'a' || str[j] == '1' || str[j] == '$') {
                    if (flag == 1) {
                        cout << "No" << endl;
                        // cout << j;
                        return 0;
                    } else {
                        break;
                    }
                }
            }
            flag = 0;
            for (int j = i; j >= 0 && j < str.size(); j--) {
                if (str[j] == '@') {
                    break;
                }
                if (str[j] == '_') {
                    flag = 1;
                }
                if (str[j] == 'a' || str[j] == '1' || str[j] == '$') {
                    if (flag == 1) {
                        cout << "No" << endl;
                        // cout << j;
                        return 0;
                    } else {
                        break;
                    }
                }
            }
        }
        }
    }

    cout << "Yes";

    return 0;
}