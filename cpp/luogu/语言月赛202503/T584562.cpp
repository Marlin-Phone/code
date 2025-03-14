#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    for (int i = 1; i < n; i++) {
        cout << vec[i] << ",";
    }
    cout << vec[n];

    return 0;
}