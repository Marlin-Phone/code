#include <iostream>
using namespace std;

const int N = 20;
int main() {
    int n, T;
    int scores1[N], scores2[N];
    int sum1 = 0, sum2 = 0;

    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        cin >> scores1[i];
        sum1 += scores1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> scores2[i];
        sum2 += scores2[i];
    }

    if (sum1 < T) {
        cout << sum1 << endl;
    } else {
        cout << sum2 << endl;
    }

    return 0;
}