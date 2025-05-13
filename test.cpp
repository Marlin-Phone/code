#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    getline(cin, str);
    // 字符串分割实现
    replace(str.begin(), str.end(), ", ", "#");

    cout << str;

    vector<string> tokens;
    istringstream iss(str);
    string token;

    while (getline(iss, token, ", ")) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << endl;
    }

    return 0;
}