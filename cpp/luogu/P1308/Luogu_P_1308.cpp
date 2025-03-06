// https://www.luogu.com.cn/problem/P1308
#include <iostream>
using namespace std;

int main() {
    string word;
    string s;
    int count = 0, firsthappen = -1;

    cin >> word;
    getchar(); // 清空缓冲区
    getline(cin, s);

    // 将字符串转换为小写
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }

    // 检查字符串s中是否包含字符串word
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == word[0] && s[i - 1] == ' ' || i == 0) {
            for (int j = 0; j < word.length(); j++) {
                if (s[i + j] != word[j]) {
                    break;
                }
                if (j == word.length() - 1 &&
                    (s[i + j + 1] == ' ' || i + j + 1 == s.length())) {
                    if (firsthappen == -1) {
                        firsthappen = i;
                    }
                    count++;
                }
            }
        }
    }

    // 输出结果
    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << count << " " << firsthappen << endl;
    }

    return 0;
}