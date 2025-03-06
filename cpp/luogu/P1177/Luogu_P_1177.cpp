// https://www.luogu.com.cn/problem/P1177
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int main() {
    int n;
    int num[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }

    return 0;
}