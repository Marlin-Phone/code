#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n";

int main() {
    IOS;
    int L, R;
    int count = 0;

    cin >> L >> R;

    for (int i = L; i <= R; i++) {
        int i0 = i;
        while (i0 > 0) {
            int wei = i0 % 10;
            i0 = i0 / 10;
            if (wei == 2) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}