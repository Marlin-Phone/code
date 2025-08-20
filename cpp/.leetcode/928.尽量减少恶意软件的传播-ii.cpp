#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=928 lang=cpp
 *
 * [928] 尽量减少恶意软件的传播 II
 */

// @lc code=start
class Solution {
  public:
    static const int MAXN = 1e5 + 10;
    vector<int> fa;
    int cnts[MAXN];
    int infect[MAXN];
    int size[MAXN];
    bool virus[MAXN];
    void init(int n, vector<int> &initial) {
        fa.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            virus[i] = false;
            cnts[i] = 0;
            infect[i] = -1;
            size[i] = 1;
        }
        for (int i : initial) {
            virus[i] = true;
        }
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return false;
        }
        fa[fx] = fy;
        size[fy] += size[fx];
        return true;
    }
    // 不是病毒的点，普通点合并
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        int n = graph.size();
        init(n, initial);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && !virus[i] && !virus[j]) {
                    merge(i, j);
                }
            }
        }
        // 病毒周围的普通点去设置源头
        for (int sick : initial) {
            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (sick != neighbor && !virus[neighbor] &&
                    graph[sick][neighbor] == 1) {
                    int fn = find(neighbor);
                    if (infect[fn] == -1) {
                        infect[fn] = sick;
                    } else if (infect[fn] != -2 && infect[fn] != sick) {
                        infect[fn] = -2;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == find(i) && infect[i] >= 0) {
                cnts[infect[i]] += size[i];
            }
        }
        sort(initial.begin(), initial.end());
        int ans = initial[0];
        int max = cnts[ans];
        for (int i : initial) {
            if (cnts[i] > max) {
                ans = i;
                max = cnts[i];
            }
        }
        return ans;
    }
};
// @lc code=end
