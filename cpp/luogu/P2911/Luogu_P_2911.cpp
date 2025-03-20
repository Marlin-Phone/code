#include <bits/stdc++.h>
using namespace std;

int s[4];
int sum = 0;
int num[1001];
int maxnum = -1e9;
int ans = 0;

int main() {
    for (int i = 1; i <= 3; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= s[1]; j++) {
            for (int k = 1; k <= s[2]; k++) {
                for (int l = 1; l <= s[3]; l++) {
                    sum = j + k + l;
                    num[sum]++;
                }
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (num[i] > maxnum) {
            maxnum = num[i];
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}