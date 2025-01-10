#include <iostream>
using namespace std;

class Student {
  public:
    string name;
    int age;   // 0-100 整数
    int score; // 0-600 的5的整倍数
};
int main() {
    int n;
    Student student[100];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> student[i].name >> student[i].age >> student[i].score;
        student[i].age++;
        student[i].score *= 1.2;
        if (student[i].score > 600) {
            student[i].score = 600;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << student[i].name << " " << student[i].age << " "
             << student[i].score << endl;
    }

    return 0;
}