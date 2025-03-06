#include <cmath>
#include <iostream>
using namespace std;

class Student {
  public:
    string name;
    int ch_score;
    int math_score;
    int en_score;
    int total_score;
};

const int N = 1e3 + 10;
int main() {
    int n;
    Student student[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> student[i].name >> student[i].ch_score >>
            student[i].math_score >> student[i].en_score;
        student[i].total_score =
            student[i].ch_score + student[i].math_score + student[i].en_score;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(student[i].ch_score - student[j].ch_score) <= 5 &&
                abs(student[i].en_score - student[j].en_score) <= 5 &&
                abs(student[i].math_score - student[j].math_score) <= 5 &&
                abs(student[i].total_score - student[j].total_score) <= 10) {
                cout << student[i].name << " " << student[j].name << endl;
            }
        }
    }

    return 0;
}