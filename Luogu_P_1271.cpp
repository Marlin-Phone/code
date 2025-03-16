#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int nums[N], cnt[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }

    sort(nums, nums + m);
    for (int i = 0; i < m; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}