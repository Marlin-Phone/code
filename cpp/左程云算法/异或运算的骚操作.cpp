#include <bits/stdc++.h>
using namespace std;

int a, b;
int nums[2] = {1, 2};
const int N = 2e5 + 10;

int sign(int x) {
    return ((x >> 31) & 1) ^ 1; // 符号位(0为负数,1为非负)
}
int getMax1(int a, int b) {
    int c = a - b;
    int returnA = sign(c);
    int returnB = returnA ^ 1;
    return a * returnA + b * returnB;
}
int getMax2(int a, int b) {
    int c = a - b; // c可能是溢出的
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    // 判断AB符号是不是不一样
    int diffAB = sa ^ sb;    // 符号位不同（一样为0，不同为1）
    int sameAB = diffAB ^ 1; // 符号位相同（一样为1，不同为0）

    int returnA = diffAB * sa + sameAB * sc; // 符号位不同，返回A
    int returnB = returnA ^ 1;               // 符号位相同，返回B

    return a * returnA + b * returnB; // 合并返回值
}

int findMissing(vector<int> &nums, int a, int b) {
    int ans = 0;
    // 得到nums数组的异或和，nums数组中有b - a个数字（缺失了一个），范围在[a, b]
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    // 得到a~b的异或和，共b - a + 1个数字
    for (int i = a; i <= b; i++) {
        ans ^= i;
    }
    // ans即为缺失的数字
    return ans;
}

int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}
int singleNumber2(vector<int> &nums, int m) {
    int ans = 0;
    int cnt1[32];
    for (auto num : nums) {
        for (int i = 0; i < 32; i++) {
            if ((num << i) & 1) {
                cnt1[i]++;
            }
        }
    }
    for (int i = 0; i < 32; i++) {
        if (cnt1[i] % m) {
            ans |= (1 << i);
        }
    }

    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << singleNumber(arr) << endl;
    return 0;
}