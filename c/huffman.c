#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char codes[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
float freq[26] = {0};
int head = 0, tail = 0;

// Huffman树的节点
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
void Sort_Freq(struct TreeNode arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - i - 1; j++) {
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
    while (tail - head >= 2) {
        // 对未合并的节点进行排序
        Sort_Freq(treenode, head, tail);
        // 取出两个最小的节点
        int left = head++;
        int right = head++;
        // 创建新节点
        treenode[tail].data = '-';
        treenode[tail].frequency =
            treenode[left].frequency + treenode[right].frequency;
        treenode[tail].left = left;
        treenode[tail].right = right;
        tail++;
    }
}

// 打印Huffman编码
int code[10];
int code_tail = 0;
void Print_Codes(int index) {
    if (treenode[index].left == -1 && treenode[index].right == -1) {
        printf("%c:", treenode[index].data);
        for (int i = 0; i < code_tail; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
        return;
    }
    // 左子树路径添加0
    code[code_tail++] = 0;
    Print_Codes(treenode[index].left);
    code_tail--;
    // 右子树路径添加1
    code[code_tail++] = 1;
    Print_Codes(treenode[index].right);
    code_tail--;
}

int main() {
    char str[] = "bbbbbbbbbbbbbbbbbacde";
    calulate_frequencies(str);
    Build_Huffman_Tree();
    // 打印所有节点的频率和树结构
    printf("Huffman Tree Nodes:\n");
    for (int i = 0; i < tail; i++) {
        printf("Node %d: %c %f left=%d right=%d\n", i, treenode[i].data,
               treenode[i].frequency, treenode[i].left, treenode[i].right);
    }
    // 打印Huffman编码
    printf("Huffman Codes:\n");
    Print_Codes(tail - 1);
    return 0;
}