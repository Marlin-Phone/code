/*
  @pintia psid=994805046380707840 pid=994805088529268736 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 日期格式化
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805088529268736
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

string str, mm, dd, yyyy;
char ch;
int cnt = 0;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        ch = str[i];
        if (ch == '\0') {
            break;
        }
        if (ch != '-') {
            if (cnt == 0) {
                mm.push_back(ch);
            } else if (cnt == 1) {
                dd.push_back(ch);
            } else {
                yyyy.push_back(ch);
            }
        } else {
            cnt++;
        }
    }

    cout << yyyy << "-" << mm << "-" << dd;
    // printf("%s-%s-%s", yyyy, mm, dd);

    return 0;
}
// @pintia code=end