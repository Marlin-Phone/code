// https://www.luogu.com.cn/problem/P5740
#include <iostream>
using namespace std;

const int N = 1e3 + 10;

class Student {
  public:
    string name;
    int ch_score;
    int math_score;
    int en_score;
    int total_score;
};

int main() {
    int n;
    int max_total_score = -1;
    Student student[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> student[i].name >> student[i].ch_score >>
            student[i].math_score >> student[i].en_score;
        student[i].total_score =
            student[i].ch_score + student[i].math_score + student[i].en_score;
        if (max_total_score < student[i].total_score) {
            max_total_score = student[i].total_score;
        }
    }

    for (int i = 0; i < n; i++) {
        if (student[i].total_score == max_total_score) {
            cout << student[i].name << " " << student[i].ch_score << " "
                 << student[i].math_score << " " << student[i].en_score << endl;
            break;
        }
    }

    return 0;
}