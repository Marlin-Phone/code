#include <iostream>
using namespace std;

long long function(int n) {
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        ans++;
        ans = ans * 2;
    }

    return ans;
}
int main() {
    int n;
    cin >> n;
    cout << function(n) << endl;

    return 0;
}