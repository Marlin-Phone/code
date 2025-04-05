#include <iostream>
using namespace std;

const int N = 110;
int T;
int n, m;
int A;

int main() {
    cin >> T;
    while (T--) {
        int minnum = 1e9, maxnum = -1;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> A;
            minnum = min(A, minnum);
            maxnum = max(A, maxnum);
        }

        if (minnum <= m && m <= maxnum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}