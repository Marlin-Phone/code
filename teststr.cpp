#include <bits/stdc++.h>
using namespace std;

char ch;
string token, str;
vector<string> tokens;

vector<string> split(const string &str, char ch) { // 待分割字符串 分割字符
    vector<string> tokens;
    string token;
    istringstream iss(str);
    while (getline(iss, token, ch)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}

int main() {
    getline(cin, str);
    cin >> ch;

    vector<string> tokens = split(str, ch);

    for (auto &token : tokens) {
        cout << '[' << token << ']' << endl;
    }

    return 0;
}
