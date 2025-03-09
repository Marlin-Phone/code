#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int n;
vector<long long> num(N);
long long minnum = 1e9 + 10;
long long maxnum = -1e9 - 10;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        minnum = min(minnum, num[i]);
        maxnum = max(maxnum, num[i]);
    }

    // if (minnum == -maxnum) {
    //     cout << 0 << endl;
    // } else {
    cout << maxnum - (minnum + maxnum) / 2 << endl;
    // }

    return 0;
}