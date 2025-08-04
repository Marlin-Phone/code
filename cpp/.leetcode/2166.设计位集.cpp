#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2166 lang=cpp
 *
 * [2166] 设计位集
 */

// @lc code=start
class Bitset {
    vector<int> a;
    int size;
    int cnt;
    bool flipped;

  public:
    Bitset(int size) {
        a.resize((size + 31) / 32);
        for (int i = 0; i < a.size(); i++) {
            a[i] = 0;
        }
        this->size = size;
        flipped = false;
        cnt = 0;
    }

    void fix(int idx) {
        int block = idx / 32;
        int pos = idx % 32;
        bool current = (a[block] >> pos) & 1;
        if (flipped) {
            if (current) { // 实际显示为0,要设为1
                a[block] &= ~(1 << pos);
                cnt--;
            }
        } else {
            if (!current) { // 实际显示为0,要设为1
                a[block] |= (1 << pos);
                cnt++;
            }
        }
    }

    void unfix(int idx) {
        int block = idx / 32;
        int pos = idx % 32;
        bool current = (a[block] >> pos) & 1;
        if (flipped) {
            if (!current) { // 实际显示为1,要设置为0
                a[block] |= (1 << pos);
                cnt++;
            }
        } else {
            if (current) { // 实际显示为0,要设置为1
                a[block] &= ~(1 << pos);
                cnt--;
            }
        }
    }
    void flip() { flipped = !flipped; }

    bool all() {
        if (flipped) {
            if (cnt == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if (cnt == size) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool one() {
        if (flipped) {
            if (size - cnt >= 1) {
                return true;
            }
            return false;
        } else {
            if (cnt >= 1) {
                return true;
            }
            return false;
        }
    }

    int count() {
        if (flipped) {
            return size - cnt;
        }
        return cnt;
    }

    string toString() {
        string str;
        for (int i = 0; i < size; i++) {
            str += to_string((a[i / 32] >> (i % 32) & 1) ^ flipped);
        }
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
// @lc code=end
