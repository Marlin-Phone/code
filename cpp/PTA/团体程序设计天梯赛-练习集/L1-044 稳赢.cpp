/*
  @pintia psid=994805046380707840 pid=994805086365007872 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 稳赢
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805086365007872
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int K;
string chuzhao;
int cnt = 0;
int flag = 0;

int main() {
    cin >> K;
    K++;
    while (1) {
        cin >> chuzhao;
        if (chuzhao == "End") {
            break;
        }

        cnt++;
        if (flag)
            cout << endl;
        flag = 1;
        if (cnt % K != 0) {
            if (chuzhao == "ChuiZi") {
                cout << "Bu";
            } else if (chuzhao == "JianDao") {
                cout << "ChuiZi";
            } else {
                cout << "JianDao";
            }
        } else {
            cout << chuzhao;
        }
    }

    return 0;
}
// @pintia code=end