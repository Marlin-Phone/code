#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long total = 0;
    for (long long x : a)
        total += x;

    const long long MAXN = total + 2;
    vector<int> left(MAXN, -1), right(MAXN, -1); // 存储左右子节点

    vector<vector<int>> layer(n);
    int root = 1;
    layer[0].push_back(root);
    int cnt = 2; // 节点编号计数器

    for (int i = 1; i < n; ++i) {
        int need = a[i]; // 当前层需要分配的节点数
        vector<int> curr;
        vector<int> &prev = layer[i - 1]; // 上一层节点列表
        int idx = 0;                      // 指向上一层当前处理的父节点

        for (int done = 0; done < need;) {
            if (idx >= prev.size()) { // 父节点不足
                cout << -1 << endl;
                return 0;
            }
            int parent = prev[idx];

            if (left[parent] == -1) { // 先填左子树
                left[parent] = cnt;
                curr.push_back(cnt++);
                done++;
            } else if (right[parent] == -1) { // 再填右子树
                right[parent] = cnt;
                curr.push_back(cnt++);
                done++;
            } else
                idx++; // 当前父节点已满，换下一个
        }
        layer[i] = curr;
    }

    // 输出结果
    cout << root << endl;
    for (int i = 1; i <= total; ++i) {
        cout << left[i] << " " << right[i] << endl;
    }

    return 0;
}