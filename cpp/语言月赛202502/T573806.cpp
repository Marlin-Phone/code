#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ::ios_base::sync_with_stdio(0);                                            \
    cin.tie(0);                                                                \
    cout.tie(0);

#define endl "\n"

const int N = 5e3 + 10;
int main() {
    IOS;
    int n, k;
    int l = 1; // 偏袒局数左边界
    int count = 0;
    int num[N];
    bool flag[N];
    int truenum = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (num[i] == 50 || num[i] == 51 || num[i] <= 51) {
            flag[i] = true;
            truenum++;
        }
    }
    // 50 49 1
    // 51 48 1
    if (truenum > n / 2) {
        cout << n - k + 1 << endl;
        exit(0);
    }

    // while (l <= n && l + k <= n) {

    //     if (num[l] == 50 || num[l] == 51) {

    //     }
    //     l++;
    // }

    cout << count << endl;

    return 0;
}