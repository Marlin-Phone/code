/*
  @pintia psid=994805046380707840 pid=994805082313310208 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 矩阵A乘以B
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805082313310208
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int r1, c1, r2, c2;
int temp;
int flag_, flagend;

void func(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> C(r1 + 1, vector<int>(c2 + 1, 0));
    for (int i = 1; i <= r1; i++) {         // A的行
        for (int j = 1; j <= c2; j++) {     // B的列
            for (int k = 1; k <= c1; k++) { // 公共维度 A的列 || B的行
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 1; i <= r1; i++) {
        if (flagend)
            cout << endl;
        flagend = 1;
        flag_ = 0;
        for (int j = 1; j <= c2; j++) {
            if (flag_)
                cout << " ";
            flag_ = 1;
            cout << C[i][j];
        }
    }
}
int main() {
    cin >> r1 >> c1;
    vector<vector<int>> A(r1 + 1);
    for (int i = 1; i <= r1; i++) {
        A[i].push_back(0);
        for (int j = 1; j <= c1; j++) {
            cin >> temp;
            A[i].push_back(temp);
        }
    }
    cin >> r2 >> c2;

    vector<vector<int>> B(r2 + 1);
    for (int i = 1; i <= r2; i++) {
        B[i].push_back(0);
        for (int j = 1; j <= c2; j++) {
            cin >> temp;
            B[i].push_back(temp);
        }
    }
    if (c1 == r2) {
        cout << r1 << " " << c2 << endl;
        func(A, B);
    } else {
        cout << "Error: " << c1 << " != " << r2;
    }

    return 0;
}
// @pintia code=end