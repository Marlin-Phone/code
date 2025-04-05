// https://www.luogu.com.cn/problem/P1781
#include <bits/stdc++.h>
using namespace std;

const int N0 = 30;
const int N = 110;
int n;
string nums[N];
int maxwei = -1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++) {
        maxwei = max(maxwei, (int)nums[i].size());
    }

    int winner = -1;
    string max_str;
    for (int i = 1; i <= n; i++) {
        if (nums[i].size() != maxwei) {
            continue;
        }
        if (nums[i] > max_str) {
            max_str = nums[i];
            winner = i;
        }
    }

    cout << winner << endl;
    cout << max_str;

    return 0;
}