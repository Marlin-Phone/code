#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    vector<int> a({1, 2, 3, 4, 5});
    reverse(a.begin(), a.end());
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}