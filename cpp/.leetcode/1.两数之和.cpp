#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string alienOrder(vector<string> &words) {
        vector<int> indegree(26, -1);
        vector<vector<int>> g(26);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                int t = words[i][j] - 'a';
                indegree[t] = 0;
            }
        }
        for (int i = 0, j, len; i < words.size() - 1; i++) {
            string cur = words[i];
            string next = words[i + 1];
            j = 0;
            len = min(cur.length(), next.length());
            for (; j < len; j++) {
                if (cur[j] != next[j]) {
                    g[cur[j] - 'a'].push_back(next[j] - 'a');
                    indegree[next[j] - 'a']++;
                    break;
                }
            }
            if (j < cur.size() && j == next.size()) {
                return "";
            }
        }
        queue<int> que;
        int kinds = 0;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] != -1) {
                kinds++;
            }
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        string ans;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            ans.push_back(cur + 'a');
            for (int next : g[cur]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    que.push(next);
                }
            }
        }
        return ans.size() == kinds ? ans : "";
    }
};