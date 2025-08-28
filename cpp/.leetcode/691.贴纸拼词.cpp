#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

// @lc code=start
class Solution {
  public:
    static const int N = 410;
    queue<string> que;
    unordered_set<string> visited;
    vector<vector<string>> g;
    string getnext(string cur, string s) {
        string res;
        int l = 0;
        int r = 0;
        while (l < cur.size() && r < s.size()) {
            if (cur[l] == s[r]) {
                l++;
                r++;
            } else if (cur[l] < s[r]) {
                res += cur[l];
                l++;
            } else {
                r++;
            }
        }
        while (l < cur.size()) {
            res += cur[l++];
        }
        return res;
    }
    int minStickers(vector<string> &stickers, string target) {
        g.resize(N);
        sort(target.begin(), target.end());
        for (auto &sticker : stickers) {
            sort(sticker.begin(), sticker.end());
        }
        // 建图
        for (int i = 0; i < stickers.size(); i++) {
            unordered_set<char> temp;
            for (int j = 0; j < stickers[i].size(); j++) {
                if (temp.count(stickers[i][j]) == 0) {
                    int idx = stickers[i][j] - 'a';
                    temp.insert(stickers[i][j]);
                    g[idx].push_back(stickers[i]);
                }
            }
        }
        visited.insert(target);
        que.push(target);
        int level = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                string cur = que.front();
                que.pop();
                for (string s : g[cur[0] - 'a']) {
                    string next = getnext(cur, s);
                    if (next == "") {
                        return level;
                    } else if (!visited.count(next)) {
                        visited.insert(next);
                        que.push(next);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
// @lc code=end
