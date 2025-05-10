#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> L(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }

    long long sum_Li = 0;
    int max_len = 0;
    for (int x : L) {
        sum_Li += x;
        max_len = max(max_len, x);
    }

    if (sum_Li < K) {
        cout << 0 << '\n';
        return 0;
    }

    int left = 1, right = max_len;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        long long cnt = 0;
        for (int x : L) {
            cnt += x / mid;
        }
        if (cnt >= K) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << '\n';
    return 0;
}
