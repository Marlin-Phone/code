#include <algorithm>
#include <iostream>
using namespace std;

const int N = 30;
bool cmp(string a, string b) { return a + b > b + a; }
int main() {
    int n;
    string num[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    std::sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << num[i];
    }

    return 0;
}