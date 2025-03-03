#include <iostream>
using namespace std;

const int N = 3010;
int n;
typedef struct {
    int in_study;
    int out_study;
} Study;
Study stu[N];
int sum = 0;
int sum0;

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stu[i].in_study >> stu[i].out_study;
        sum = sum + stu[i].in_study + stu[i].out_study - 8;
        sum0 += sum;
    }

    cout << sum0 << endl;

    return 0;
}