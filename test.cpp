#include <bits/stdc++.h>

void testRandQuality() {
    // 测试 rand() 的低位分布
    std::vector<int> counts(2, 0);
    for (int i = 0; i < 10000; ++i) {
        counts[rand() % 2]++; // 统计 0 和 1 的出现次数
    }
    std::cout << "0: " << counts[0] << ", 1: " << counts[1] << std::endl;
    // 理想情况应该接近 5000:5000，但 rand() 可能偏差较大
}

int main() {
    srand(12345); // 固定种子便于观察

    // 测试连续三个数的模式
    for (int i = 0; i < 10; ++i) {
        int a = rand() % 2;
        int b = rand() % 2;
        int c = rand() % 2;
        std::cout << a << b << c << " ";
    }
    // 某些 rand() 实现可能显示出可预测的模式
}