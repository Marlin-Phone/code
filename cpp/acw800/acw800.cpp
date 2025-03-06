#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int num1[N], num2[N];

int main() {
    int target;
    int n, m;
    cin >> target;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num1[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> num2[j];
    }

    int i = 0;
    int j = m - 1;
    while (num1[i] + num2[j] != target) {
        if (num1[i] + num2[j] > target) {
            j--;
        } else if (num1[i] + num2[j] < target) {
            i++;
        }
        // cout << num1[i] << " " << num2[j] << endl;
    }

    cout << num1[i] << " " << num2[j] << endl;

    return 0;
}