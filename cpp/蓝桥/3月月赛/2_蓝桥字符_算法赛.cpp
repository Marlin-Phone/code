#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long count_l = 0, count_la = 0, count_lan = 0;
    for (char c : s) {
        if (c == 'l') {
            count_l++;
        } else if (c == 'a') {
            count_la += count_l;
        } else if (c == 'n') {
            count_lan += count_la;
        }
    }
    cout << count_lan << endl;
    return 0;
}
