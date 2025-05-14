#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> ans;

int main() {
    getline(cin, str);
    if (str.empty()) {
        return 0;
    }

    size_t start = 0;

    for (size_t i = 0; i < str.size();) {
        if (str[i] == ',' || str[i] == ' ') {
            if (i > start) {
                ans.push_back(str.substr(start, i - start));
            }
            start = i + 1;
        }
        i++;
    }
    if (start < str.size()) {
        ans.push_back(str.substr(start));
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}