#include <bits/stdc++.h>
using namespace std;

int a, b;
int nums[2] = {1, 2};

int main() {
    cin >> a >> b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;

    // ----------------------------------------------------------------------

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}