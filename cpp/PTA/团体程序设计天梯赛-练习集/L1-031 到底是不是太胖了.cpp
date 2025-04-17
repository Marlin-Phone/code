/*
  @pintia psid=994805046380707840 pid=994805102173339648 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 到底是不是太胖了
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805102173339648
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n;
double H, W;
int flag = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> H >> W;
        W /= 2;
        double goodW = (H - 100) * 0.9;
        if (abs(goodW - W) < goodW * 0.1) {
            if (flag)
                cout << endl;
            flag = 1;
            cout << "You are wan mei!";
        } else if (goodW - W < 0) {
            if (flag)
                cout << endl;
            flag = 1;
            cout << "You are tai pang le!";
        } else if (goodW - W > 0) {
            if (flag)
                cout << endl;
            flag = 1;
            cout << "You are tai shou le!";
        }
    }

    return 0;
}
// @pintia code=end