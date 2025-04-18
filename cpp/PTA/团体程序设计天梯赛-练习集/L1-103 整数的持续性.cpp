/*
  @pintia psid=994805046380707840 pid=1781658570803388422 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 整数的持续性
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388422
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int a, b;
int maxm = -1e9;
vector<int> nums;
int flag;

int getm(int num) {
    int cnt = 0;
    while (num > 9) {
        int ans = 1;
        int temp;
        while (num > 0) {
            temp = num % 10;
            num /= 10;
            ans *= temp;
        }
        num = ans;
        cnt++;
    }

    return cnt;
}
int main() {
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        m = getm(i);
        if (m == maxm) {
            nums.push_back(i);
        } else if (m > maxm) {
            maxm = m;
            nums.clear();
            nums.push_back(i);
        }
        // maxm = max(maxm, m);
    }

    cout << maxm << endl;
    for (size_t i = 0; i < nums.size(); i++) {
        if (flag)
            cout << " ";
        flag = 1;
        cout << nums[i];
    }
    return 0;
}
// @pintia code=end