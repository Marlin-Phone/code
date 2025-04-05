#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int a;
    int b;
};

bool compare(const Node &x, const Node &y) {
    bool x_front = (x.a <= x.b);
    bool y_front = (y.a <= y.b);
    if (x_front != y_front) {
        return x_front;
    } else {
        if (x_front) {
            return x.a < y.a;
        } else {
            return x.b > y.b;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<Node> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].a;
    }
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].b;
    }
    sort(tasks.begin(), tasks.end(), compare);

    int sumA = 0;
    int prevB_end = 0;
    for (const auto &task : tasks) {
        sumA += task.a;
        int currB_start = max(prevB_end, sumA);
        prevB_end = currB_start + task.b;
    }

    cout << prevB_end << endl;
    return 0;
}
