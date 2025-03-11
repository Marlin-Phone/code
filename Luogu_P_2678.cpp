#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int l;     // 起点到终点的距离
int n;     // 起点和终点之间的岩石数
int m;     // 组委会至多移走的岩石数
           // D[i] 表示第i块岩石距起点的距离
int dx[N]; // 差分

int main() {
    cin >> l >> n >> m;
    vector<int> D(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
    }
    int m0 = m;
    while (m--) {
        int mindx = 1e9;
        for (int i = 1; i < n - (m0 - m); i++) {
            dx[i] = D[i] - D[i - 1];
            // cout << dx[i] << " ";
            mindx = min(dx[i], mindx);
        }
        for (int i = 1; i < n - (m0 - m); i++) {
            if (dx[i] == mindx) {
                D.erase(D.begin() + i);
            }
        }
    }

    // cout << endl;

    int mindx = 1e9;
    for (int i = 1; i <= n - m0; i++) {
        dx[i] = D[i] - D[i - 1];
        // cout << dx[i] << " ";
        mindx = min(dx[i], mindx);
    }
    // cout << endl;
    if (mindx == 1e9)
        mindx = l;
    cout << mindx;

    return 0;
}