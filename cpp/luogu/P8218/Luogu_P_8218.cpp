// https://www.luogu.com.cn/problem/P8218
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> vec(N);
vector<int> sumnums(N);
int times;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        sumnums[i] = sumnums[i - 1] + vec[i];
    }

    cin >> times;
    while (times--) {
        int l, r;
        cin >> l >> r;
        cout << sumnums[r] - sumnums[l - 1] << endl;
    }

    return 0;
}