/*
  @pintia psid=994805046380707840 pid=994805099426070528 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 出生年
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805099426070528
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int y, x, n;
int year[4];
set<int> st;

int check(int x) {
    // cout << "x = " << x << endl;
    int cnt = 0;
    st.clear();

    for (int i = 0; i < 4; i++) {
        year[i] = x % 10;
        x /= 10;
    }
    // for (int i = 0; i < 4; i++) {
    //     cout << year[i];
    // }
    // cout << endl;
    for (int i = 0; i < 4; i++) {
        if (st.count(year[i]) == 0) {
            st.insert(year[i]);
            cnt++;
        }
    }

    // cout << "x = " << x;
    // cout << " cnt = " << cnt << endl;
    return cnt;
}
int main() {
    cin >> y >> n;

    for (int i = y; i <= 9999; i++) {
        if (check(i) == n) {
            x = i - y;
            printf("%d %04d", x, i);
            break;
        }
    }

    return 0;
}
// @pintia code=end