#include <bits/stdc++.h>
using namespace std;

int s1, s2, s3, s4;

int main() {
    cin >> s1 >> s2 >> s3 >> s4;
    vector<int> A(s1); // 第一科习题集每道题目所消耗的时间
    vector<int> B(s2);
    vector<int> C(s3);
    vector<int> D(s4);

    for (int i = 0; i < s1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < s2; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < s3; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < s4; i++) {
        cin >> D[i];
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s1; j++) {
            for (int k = j + 1; k < s1; k++) {
            }
        }
    }
    for (int i = 0; i < s2; i++) {
    }
    for (int i = 0; i < s3; i++) {
    }
    for (int i = 0; i < s4; i++) {
    }

    return 0;
}