#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
  public:
    int ladderLength(string begin, string end, vector<string> &wordList) {
        unordered_set<string> smallLevel, bigLevel, nextLevel, dict;
        for (auto word : wordList) {
            dict.insert(word);
        }
        if (!dict.count(end)) {
            return 0;
        }
        smallLevel.insert(begin);
        bigLevel.insert(end);
        for (int len = 2; !smallLevel.empty(); len++) {
            for (string w : smallLevel) {
                string word = w;
                for (int j = 0; j < word.size(); j++) {
                    char old = word[j];
                    for (char change = 'a'; change <= 'z'; change++) {
                        if (change != old) {
                            word[j] = change;
                            string next = word;
                            if (bigLevel.count(next)) {
                                return len;
                            }
                            if (dict.count(next)) {
                                dict.erase(next);
                                nextLevel.insert(next);
                            }
                        }
                    }
                    word[j] = old;
                }
            }
            if (nextLevel.size() <= bigLevel.size()) {
                swap(nextLevel, smallLevel);
            } else {
                unordered_set<string> tmp = smallLevel;
                smallLevel = bigLevel;
                bigLevel = nextLevel;
                nextLevel = tmp;
            }
            nextLevel.clear();
        }
        return 0;
    }
};
// @lc code=end
