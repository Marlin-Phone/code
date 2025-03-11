// https://www.luogu.com.cn/problem/P1102
// 暴力二分法
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, c;
long long ans = 0;

int main() {
    cin >> n >> c;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for (int i = n - 1; i >= 0; i--) {
        int j = lower_bound(vec.begin(), vec.end(), vec[i] - c) - vec.begin();
        int k = upper_bound(vec.begin(), vec.end(), vec[i] - c) - vec.begin();
        // cout << "j = " << j << " " << "k = " << k << endl;
        ans += k - j;
    }

    cout << ans;

    return 0;
}