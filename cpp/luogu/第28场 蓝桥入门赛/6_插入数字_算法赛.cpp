#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k = s.size();
    unordered_set<string> result;

    for (int i = 0; i <= k; ++i) {
        for (int d = 0; d <= 9; ++d) {
            if (i == 0 && d == 0)
                continue; // 开头不能插入0
            char c = '0' + d;
            string new_s;
            if (i == 0) {
                new_s = string(1, c) + s;
            } else if (i == k) {
                new_s = s + string(1, c);
            } else {
                new_s = s.substr(0, i) + c + s.substr(i);
            }
            result.insert(new_s);
        }
    }

    cout << result.size() << endl;
    return 0;
}