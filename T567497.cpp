#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    unordered_map<int, int> constraints;
    vector<int> unique_x;

    // 读取输入
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        if (y > 0) {
            constraints[x] = y;
            unique_x.push_back(x);
        }
    }

    // 找到最大的 MEX 值
    int max_mex = unique_x.empty()
                      ? 0
                      : *max_element(unique_x.begin(), unique_x.end()) + 1;
    vector<int> result;

    // 构造结果数组
    for (int i = 0; i <= max_mex; ++i) {
        if (constraints.count(i)) {
            int count = constraints[i];
            for (int j = 0; j < count; ++j) {
                result.push_back(i);
            }
        }
    }

    // 检查累积 MEX 值是否符合要求
    vector<int> B;
    unordered_map<int, int> freq;
    for (int i = 0; i < result.size(); ++i) {
        freq[result[i]]++;
        int mex = 0;
        while (freq.count(mex)) {
            mex++;
        }
        B.push_back(mex);
    }

    // 检查 B 中每个数的出现次数是否符合
    unordered_map<int, int> B_count;
    for (int b : B) {
        B_count[b]++;
    }

    for (const auto &[x, y] : constraints) {
        if (B_count[x] != y) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 输出结果
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
