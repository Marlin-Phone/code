#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
int n, k;
int num;
priority_queue<int> pque;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        pque.push(num);
        while (pque.size() > k + 1) {
            // cout << pque.top() << endl;
            pque.pop();
        }
    }

    // cout << pque.size() << endl;
    cout << pque.top();

    return 0;
}