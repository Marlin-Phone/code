#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
  public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(),
             [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        priority_queue<int> heap;
        int time = 0;
        for (auto c : courses) {
            if (time + c[0] <= c[1]) {
                heap.push(c[0]);
                time += c[0];
            } else {
                if (!heap.empty() && heap.top() > c[0]) {
                    time -= heap.top();
                    heap.pop();
                    heap.push(c[0]);
                    time += c[0];
                }
            }
        }
        return heap.size();
    }
};
// @lc code=end
