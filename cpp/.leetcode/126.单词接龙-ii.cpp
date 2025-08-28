#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
  public:
    // 我嘞个豆还有这么好用的stl
    //  unordered_set
    // 功能：unordered_set
    // 是一个不允许重复元素的集合容器，使用哈希表存储元素，元素之间没有顺序。
    // 元素存储：存储的只是单独的元素，没有与之关联的“值”。
    // 使用场景：当你只关心集合中的元素是否存在，而不关心元素的顺序时，可以使用
    // unordered_set。
    // 操作：常用操作有插入、删除、查找元素，所有这些操作的时间复杂度都是
    // O(1)，但最坏情况下是 O(n)，如果哈希冲突过多。
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        unordered_set<string> dic(wordList.begin(),
                                  wordList.end()); // 把wordlist复制到哈希表里
        if (dic.find(endWord) == dic.end())
            return {}; // c++20才支持contains,fw vscode
        unordered_map<string, vector<string>> gra; // 反图
        // 类似滚动数组的想法
        unordered_set<string> curl,
            nextl; // 当前层和下一层，滚动更新，不用每次都新建hash表了
        curl.insert(beginWord);
        bool fl = false;
        // 开始bfs建图
        // 本题核心思想，不是遍历字典里的字符串两两比较去建图找最短路，这样建图是n方复杂度，然后跑bfs又是O(m+n)边加点，包似的
        // 把思路反过来，由于字符串长度<=5，英文只有26个英文字母，我去遍历每个字符串只换一个字母可能生成的字符串（类似22南京站密码锁bfs搜索四位密码的全排列），如果生成的字符串在字典中存在，连边
        while (!curl.empty()) {
            for (auto str : curl) {
                dic.erase(str);
            } // 每遍历一层，删去这一层的单词，防止重复生成
            for (string cur : curl) {
                string nxt = cur;
                for (int j = 0; j < cur.length(); j++) {
                    char o = nxt[j]; // 换字母
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        nxt[j] = ch;
                        if (dic.find(nxt) != dic.end()) {
                            nextl.insert(nxt);       // 记录生成层
                            gra[nxt].push_back(cur); // 连边
                            if (nxt == endWord)
                                fl = true;
                        }
                    }
                    nxt[j] = o; // 记得复原母单词
                }
            }
            if (fl)
                break; // 在当前层已经找到合法最短路
            curl = nextl;
            nextl.clear(); // 滚动数组,nextl赋值给curl
        }
        vector<vector<string>> ans; // 答案
        vector<string> path;
        // 跟左神学一手lambda表达式递归调用
        auto dfs = [&](auto &&dfs, const string &cur) -> void {
            path.push_back(cur);
            if (cur == beginWord) {
                ans.push_back({path.rbegin(), path.rend()});
                path.pop_back(); // 这条路径已经存到结果数组里了
                return;
            }
            for (const string &str : gra[cur]) {
                dfs(dfs, str);
            }
            path.pop_back();
        };
        // 这个图建出来就是答案图，dfs只是用来回溯记录答案
        if (fl) {
            dfs(dfs, endWord);
            return ans;
        } else
            return {};
    }
};
// @lc code=end
