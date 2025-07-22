#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << endl

int solution(int n, vector<int> &a) {
    if (n == 1) {
        return 1;
    }
    if (a[0] > a[1]) {
        return 0;
    }
    if (a[n - 2] < a[n - 1]) {
        return n - 1;
    }

    for (int i = 1; i <= n - 2; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 10, 0);
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];
    }

    cout << solution(n, a);

    return 0;
}