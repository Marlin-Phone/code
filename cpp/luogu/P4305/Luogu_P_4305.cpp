// https://luogu.com.cn/problem/P4305
// 集合 | 映射 | 数组
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 5e4 + 10;
int T;
int n;
vector<int> nums;
int temp;
map<int, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        mp.clear();
        nums.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            if (mp[temp] == 0) {
                mp[temp] = 1;
                nums.push_back(temp);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}