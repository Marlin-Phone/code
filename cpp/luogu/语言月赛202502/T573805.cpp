#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ::ios_base::sync_with_stdio(0);                                            \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

int main() {
    int X, Y, K;
    cin >> X >> Y >> K;
    int temp;
    int count = 0;
    int ans = 0;
    for (int i = 0; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            for (int k = 0; k <= K; k++) {
                temp = (i + j) ^ k;
                if (temp > ans) {
                    count = 0;
                    ans = temp;
                }
                if (temp == ans)
                    count++;
            }
        }
    }

    cout << ans << endl;
    cout << count << endl;
    return 0;
}