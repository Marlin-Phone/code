#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long x;
    long long sum_a = 0;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }

    long long max_gain = x - a[0];
    long long current = max_gain;

    for (int i = 1; i < n; ++i) {
        long long diff = x - a[i];
        current = max(diff, current + diff);
        max_gain = max(max_gain, current);
    }

    cout << sum_a + max(max_gain, 0LL) << endl;
    return 0;
}