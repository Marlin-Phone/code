#include <bits/stdc++.h>
using namespace std;

vector<int> prm;
vector<int> ling;
int minnum = 1e9;
long long ans = 0;

bool isprime(int x) {
    for (int i = 2; i < sqrt(x) + 1; i++) {
        if (x == 2) {
            return true;
        }
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}
bool isling(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % (i * i) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (isprime(i)) {
            prm.push_back(i);
        }
        if (isling(i)) {
            ling.push_back(i);
        }
    }

    // for (auto it = prm.begin(); it != prm.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // for (auto it = ling.begin(); it != ling.end(); it++) {
    //     cout << *it << " ";
    // }

    for (auto it = prm.begin(); it < prm.end(); it++) {
        for (auto jt = ling.begin(); jt < ling.end(); jt++) {
            if (*it + *jt == n) {
                ans++;
                minnum = min(minnum, abs(*it - *jt));
            }
        }
    }

    cout << ans << endl;
    cout << minnum;

    return 0;
}