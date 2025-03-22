#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
bool st[N];
vector<int> arr(N);
vector<vector<int>> ways;
int cnt;

void dfs(int x) {
    if (x > n) {
        // for (int i = 1; i <= n; i++) {
        //     // cout << arr[i] << " ";
        // }
        ways.push_back(arr);
        cnt++;
        // cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i] == true) {
            continue;
        }
        st[i] = true;
        arr[x] = i;
        dfs(x + 1);
        st[i] = false;
        arr[x] = 0;
    }
}
int main() {
    cin >> n;
    dfs(1);
    for (int i = 0; i < ways.size(); i++) {
        for (int j = 1; j <= n; j++) {
            cout << ways[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}