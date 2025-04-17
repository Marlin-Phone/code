/*
  @pintia psid=994805046380707840 pid=994805097018540032 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 情人节
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805097018540032
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

string temp;
vector<string> name;

int main() {
    while (1) {
        cin >> temp;
        if (temp[0] == '.') {
            break;
        }
        name.push_back(temp);
    }
    if (name.size() >= 14) {
        cout << name[1] << " and " << name[13]
             << " are inviting you to dinner...";
    } else if (name.size() >= 2) {
        cout << name[1] << " is the only one for you...";
    } else {
        cout << "Momo... No one is for you ...";
    }

    return 0;
}
// @pintia code=end