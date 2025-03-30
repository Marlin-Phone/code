#include <bits/stdc++.h>
using namespace std;

const int N = 40;
int score;
int scores[N];
int cq_sec_score;
int tir_score = 40;

int main() {
    cin >> score;
    for (int i = 1; i <= 32; i++) {
        cin >> scores[i];
        if (i == 3) {
            cq_sec_score = scores[i] - 1;
        }
    }

    if (score >= scores[1]) {
        cout << "sidekick";
    } else if (score >= cq_sec_score) {
        cout << "sgnd";
    } else if (score >= 40) {
        cout << "cxq";
    } else {
        cout << "kiku";
    }

    return 0;
}