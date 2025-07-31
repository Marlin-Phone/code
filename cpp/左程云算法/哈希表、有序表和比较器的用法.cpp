#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << endl;

struct Point {
    int x, y;
};
struct PointCmp { // 自定义比较规则
    bool operator()(const Point &a,
                    const Point &b) const { // 必须声明为const成员函数
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    }
};

struct MinHeapCmp {
    bool operator()(const int &a, const int &b) const { return a > b; }
};
priority_queue<int> maxHeap; // 默认最大堆，无需显式说明
priority_queue<int, vector<int>, MinHeapCmp> minHeap;      // 最小堆
priority_queue<int, vector<int>, greater<int>> minHeapStd; //
// 最小堆，使用标准库中的比较规则

int main() {

    set<Point, PointCmp> pset;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pset.insert({a, b});
    }

    for (auto [a, b] : pset) {
        cout << a << endl;
        cout << b << endl;
        cout << endl;
    }
}