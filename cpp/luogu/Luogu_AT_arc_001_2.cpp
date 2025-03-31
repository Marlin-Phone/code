// Unknown Error 所有提交都是未知错误, 估计是评测机有问题.
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int A, B;
int dx[6] = {1, -1, 5, -5, 10, -10};
queue<pair<int, int>> q;
int cnt = 0;

int bfs(int x) {
    q.push({x, 0});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int a = t.first + dx[i];
            cnt = t.second + 1;

            if (a == B) {
                return cnt;
            }
            q.push({a, cnt});
        }
    }
    return -1;
}
int main() {
    cin >> A >> B;
    if (A == B) {
        cout << 0;
        return 0;
    }
    cout << bfs(A);

    return 0;
}