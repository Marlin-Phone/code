#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int teacher = 1;
    while (m--) {
        if (teacher == 0) {
            teacher = n;
        }
        int step = a[teacher];
        while (step--) {
            if (teacher == 0) {
                teacher = n;
            }
            teacher--;
        }
    }

    if (teacher == 0) {
        teacher = n;
    }

    cout << teacher;

    return 0;
}