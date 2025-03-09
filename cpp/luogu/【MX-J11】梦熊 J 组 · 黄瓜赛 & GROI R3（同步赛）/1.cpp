#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int num[N];
bool flag[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (num[i] == 0)
            flag[i + 1] = true;
        if (num[i] == 1)
            flag[i - 1] = true;
    }

    if (flag[k] == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}