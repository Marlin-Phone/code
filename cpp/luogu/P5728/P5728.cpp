#include <iostream>
using namespace std;

const int N = 1e3 + 10;

class Student {
  public:
    int ch_score;
    int math_score;
    int en_score;
    int total_score;
};
int main() {
    int n;
    int count = 0;
    Student stu[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].ch_score >> stu[i].math_score >> stu[i].en_score;
        stu[i].total_score =
            stu[i].ch_score + stu[i].math_score + stu[i].en_score;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(stu[i].ch_score - stu[j].ch_score) <= 5 &&
                abs(stu[i].en_score - stu[j].en_score) <= 5 &&
                abs(stu[i].math_score - stu[j].math_score) <= 5 &&
                abs(stu[i].total_score - stu[j].total_score) <= 10) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
