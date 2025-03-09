#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(8) << max(a, b) * 1.0 << endl;
    return 0;
}