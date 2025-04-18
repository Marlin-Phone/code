/*
  @pintia psid=994805046380707840 pid=1781658570803388418 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 帮助色盲
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388418
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    if (B == 1 || A == 2) {
        cout << "-" << endl;
        if (A == 0 || A == 2) {
            cout << "stop";
        } else if (A == 1) {
            cout << "move";
        }
    } else {
        if (A == 0) {
            cout << "biii" << endl;
            cout << "stop";
        } else if (A == 1) {
            cout << "dudu" << endl;
            cout << "move";
        }
    }

    return 0;
}
// @pintia code=end