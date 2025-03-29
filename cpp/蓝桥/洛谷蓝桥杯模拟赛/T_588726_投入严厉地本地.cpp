#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T; // 读取测试组数
    while (T--) {
        string s, t;
        int k;
        cin >> s >> t >> k; // 读取输入字符串s, t和整数k

        unordered_map<string, string> mapping; // 存储映射规则
        int n = s.length();
        int m = 0; // 用于记录规则数量

        // 寻找所有的长度为k的后缀，并尝试生成t
        for (int i = 0; i <= n - k; ++i) {
            string suffix = s.substr(i, k);                // 获取长度为k的后缀
            char nextChar = (i + k < n) ? s[i + k] : '\0'; // 获取后续的字符

            string replacement = "";
            if (nextChar != '\0') {
                replacement += nextChar; // 若有后续字符，作为替代字符
            }

            mapping[suffix] = replacement; // 存储到映射规则中
        }

        // 由于规则数量限制在50以内，我们输出所有有效规则
        for (const auto &rule : mapping) {
            if (m >= 50)
                break; // 确保不超过50条规则
            cout << "(" << rule.first << "," << rule.second << ")" << endl;
            m++;
        }

        cout << m << endl; // 输出规则数量
    }

    return 0;
}
