/*
  @pintia psid=994805046380707840 pid=994805090748055552 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 最佳情侣身高差
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805090748055552
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int n;
char sex;
double H;
int flag;

int main() {
    cin >> n;
    while (n--) {
        cin >> sex >> H;
        if (sex == 'M') {
            if (flag)
                cout << endl;
            flag = 1;
            printf("%.2lf", H / 1.09);
            // cout << H / 1.09;
        } else {
            if (flag)
                cout << endl;
            flag = 1;
            printf("%.2lf", H * 1.09);
        }
    }

    return 0;
}
// @pintia code=end