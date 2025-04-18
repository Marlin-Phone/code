/*
  @pintia psid=994805046380707840 pid=1781658570803388424 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 鱼与熊掌
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388424
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
// #define debug(x) cout << "#x = " << #x << endl;

const int N = 1e5;
int n, m; // 总人数 物品种类总数
int K[N];
vector<vector<int>> M;
int Q;
int flag;

int main() {
    cin >> n >> m;
    // vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> K[i];
        vector<int> temp(K[i]);
        for (int j = 0; j < K[i]; j++) {
            cin >> temp[j];
        }
        M.push_back(temp);
    }

    cin >> Q;
    while (Q--) {
        int idx1, idx2;
        int cnt = 0;
        cin >> idx1 >> idx2;

        for (int i = 0; i < n; i++) {
            int flag1 = 0, flag2 = 0;
            for (int j = 0; j < K[i]; j++) {
                if (M[i][j] == idx1) {
                    flag1 = 1;
                }
                if (M[i][j] == idx2) {
                    flag2 = 1;
                }
                if (flag1 == 1 && flag2 == 1) {
                    cnt++;
                    break;
                }
            }
        }

        if (flag) {
            cout << endl;
        }
        flag = 1;
        cout << cnt;
    }

    return 0;
}
// @pintia code=end