// https://www.luogu.com.cn/problem/P2141
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, count = 0, flag = 0;

    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    for (int i = n - 1; i >= 2; i--) {
        for (int j = i - 1; j >= 1; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (num[i] == num[j] + num[k]) {
                    count++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        flag = 0;
    }
    cout << count << endl;

    return 0;
}