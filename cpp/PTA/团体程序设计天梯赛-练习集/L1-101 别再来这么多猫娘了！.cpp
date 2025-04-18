/*
  @pintia psid=994805046380707840 pid=1781658570803388420 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 别再来这么多猫娘了！
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388420
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x;

const int N = 110;
int n;
string word[N];
string str;
int k;
int cnt = 0;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    cin >> n;
    // debug(n);
    for (int i = 1; i <= n; i++) {
        cin >> word[i];
    }
    cin >> k;
    getchar();
    getline(cin, str);
    // cout << "test" << endl;
    for (int i = 1; i <= n; i++) {
        size_t pos = 0;
        while ((pos = str.find(word[i], pos)) != string::npos) {
            str.replace(pos, word[i].length(), "<censored>");
            cnt++;
            pos += 1;
        }
    }

    if (cnt >= k) {
        cout << cnt << endl;
        cout << "He Xie Ni Quan Jia!";
    } else {
        cout << str;
    }

    return 0;
}
// @pintia code=end