#include <iostream>
using namespace std;

const int N = 1e3 + 10;

class Student {
  public:
    int id;
    double study_score;
    double other_score;
    double mix_score;
};
int main() {
    int n;
    Student stu[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].id >> stu[i].study_score >> stu[i].other_score;
        stu[i].mix_score = stu[i].study_score * 7 + stu[i].other_score * 3;
        if (stu[i].mix_score >= 800 &&
            stu[i].study_score + stu[i].other_score > 140) {
            cout << "Excellent" << endl;
        } else {
            cout << "Not excellent" << endl;
        }
    }

    return 0;
}