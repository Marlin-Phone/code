#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3 + 10;

// 二分查找某一元素
int binary_search(vector<int> &num, int n, int val) {
    int i = -1, j = n;
    while (i + 1 != j) {
        int mid = i + (j - i) / 2;
        if (num[mid] < val)
            i = mid;
        else
            j = mid;
    }
    if (num[j] == val)
        return j;
    else
        return -1;
}
// 二分查找<val的最后一个元素
int binary_search_2(vector<int> &num, int n, int val) {
    int i = -1, j = n;
    while (i + 1 != j) {
        int mid = i + (j - i) / 2;
        if (num[mid] < val)
            i = mid;
        else
            j = mid;
    }
    return i;
}

int main() {
    int n, val;
    vector<int> num(N);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << binary_search(num, n, 5) << endl; // 二分查找5的第一个位置
    cout << binary_search_2(num, n, 0) << endl; // 查找<0的最后一个元素
    return 0;
}