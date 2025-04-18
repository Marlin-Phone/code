/*
  @pintia psid=994805046380707840 pid=1781658570803388423 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 九宫格
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388423
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
int g[N][N];
map<int, int> mp;
int flag;

int main() {
    cin >> n;
    while (n--) {
        int flag0 = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cin >> g[i][j];
                if (g[i][j] > 9 || g[i][j] < 1) {
                    flag0 = 1;
                }
            }
        }
        if (flag0 == 1) {
            goto the_end;
        }

        for (int i = 1; i <= 9; i++) { // 每一行判断
            mp.clear();
            for (int j = 1; j <= 9; j++) {
                if (mp.count(g[i][j]) == 0) {
                    mp[g[i][j]]++;
                } else {
                    flag0 = 1;
                    goto the_end;
                }
            }
        }

        for (int j = 1; j <= 9; j++) {
            mp.clear();
            for (int i = 1; i <= 9; i++) {
                if (mp.count(g[i][j]) == 0) {
                    mp[g[i][j]]++;
                } else {
                    flag0 = 1;
                    goto the_end;
                }
            }
        }

        for (int k = 0; k <= 2; k++) {
            for (int l = 0; l <= 2; l++) {
                mp.clear();
                for (int i = 1 + 3 * k; i <= 3 + 3 * k; i++) {
                    for (int j = 1 + 3 * l; j <= 3 + 3 * l; j++) {
                        if (mp.count(g[i][j]) == 0) {
                            mp[g[i][j]]++;
                        } else {
                            flag0 = 1;
                            goto the_end;
                        }
                    }
                }
            }
        }

    the_end:
        if (flag0 == 1) {
            if (flag) {
                cout << endl;
            }
            flag = 1;
            cout << 0;
            // continue;
        } else {
            if (flag) {
                cout << endl;
            }
            flag = 1;
            cout << 1;
            // continue;
        }
    }

    return 0;
}
// @pintia code=end