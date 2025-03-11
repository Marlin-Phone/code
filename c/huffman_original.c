#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char codes[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
float freq[26] = {0};
int head, tail = 0;

// Huffman树的节点(模拟链表)
struct TreeNode {
    char data;
    float frequency;
    int left, right;
} treenode[57];

// 计算字符频率
void calulate_frequencies(char str[]) {
    int count = strlen(str);
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < 26; j++) {
            if (str[i] == codes[j]) {
                freq[j]++;
                break;
            }
        }
    }
    for (size_t i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            treenode[tail].data = codes[i];
            treenode[tail].frequency = freq[i] / (float)count;
            treenode[tail].left = -1;
            treenode[tail].right = -1;
            tail++;
        }
    }
}

// 用冒泡排序排列频率
void Sort_Freq(struct TreeNode arr[]) {
    // 问题1：排序范围错误
    // 原始代码中，排序范围是从head到tail-1，但head的值没有正确初始化（默认为0）
    // 这会导致排序时可能包含已经合并的节点
    for (int i = head; i < tail - 1; i++) {
        for (int j = head; j < tail - i - 1; j++) {
            if (arr[j].frequency > arr[j + 1].frequency) {
                struct TreeNode temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 构建Huffman树
void Build_Huffman_Tree() {
    // 问题2：循环条件错误
    // 原始代码中，循环条件是`head < tail - 1 || head == 0`
    // 这会导致在某些情况下无法正确合并所有节点
    while (head < tail - 1 || head == 0) {
        float sum_freq = 0;
        Sort_Freq(treenode);
        // 问题3：合并逻辑错误
        // 原始代码中，合并时直接使用head和head+1，但没有确保这两个节点是当前最小的
        treenode[tail].left = head;
        sum_freq = sum_freq + treenode[head].frequency;
        head++;
        treenode[tail].right = head;
        sum_freq = sum_freq + treenode[head].frequency;
        head++;
        treenode[tail].data = '-';
        treenode[tail].frequency = sum_freq;
        tail++;
    }
}

// 打印Huffman编码
int code[10];
int code_tail = 0;
int Print_Codes(int index) {
    if (treenode[index].left == -1 && treenode[index].right == -1) {
        printf("%c:", treenode[index].data);
        for (size_t i = 0; i < code_tail; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
        return 1;
    }
    code[code_tail] = 0;
    code_tail = code_tail + 1;
    Print_Codes(treenode[index].left);
    code_tail = code_tail - 1;
    code[code_tail] = 1;
    code_tail = code_tail + 1;
    Print_Codes(treenode[index].right);
    code_tail = code_tail - 1;
}

int main() {
    char str[] = "cbdbaceba";
    calulate_frequencies(str);
    Build_Huffman_Tree();
    // 打印所有节点的频率
    for (int i = 0; i < tail; i++) {
        printf("%c:%f\n", treenode[i].data, treenode[i].frequency);
    }
    Print_Codes(tail - 1);
    return 0;
}