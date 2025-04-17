/*
  @pintia psid=994805046380707840 pid=994805083282194432 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 装睡
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805083282194432
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int n;
int pin, mai;
string name;
int flag = 0;

int main() {
    cin >> n;
    while (n--) {
        cin >> name >> pin >> mai;
        if (!(pin <= 20 && pin >= 15)) {
            if (flag)
                cout << endl;
            flag = 1;
            cout << name;
        } else if (!(mai <= 70 && mai >= 50)) {
            if (flag)
                cout << endl;
            flag = 1;
            cout << name;
        }
    }

    return 0;
}
// @pintia code=end