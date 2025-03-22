#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
long long sum = 0;

struct Class {
    int a, b, c;
};
struct Class classes[N];

bool compare(const Class &c1, const Class &c2) { return c1.c > c2.c; }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> classes[i].a >> classes[i].b;
        classes[i].c = classes[i].a - classes[i].b;
    }

    sort(classes + 1, classes + 1 + n, compare);

    // for (int i = 1; i <= n; i++) {
    //     cout << c[i] << " ";
    // }

    for (int i = 1; i <= n; i++) {
        if (i <= n / 2) {
            sum += classes[i].a;
        } else {
            sum += classes[i].b;
        }
    }

    cout << sum;

    return 0;
}