#include <bits/stdc++.h>
using namespace std;

const int N = 100;
string str;
int n;
int nums[N];
bool st[N];
vector<vector<int>> ans;

void dfs(int x) {
    if (x > n) {

        return;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i])
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    sort(nums + 1, nums + 1 + n);
    dfs(1);

    return 0;
}