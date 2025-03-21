// https://www.luogu.com.cn/problem/P1003
#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int a, b, g, k; // 起点坐标和x y 方向上的长度
} Node;
int n;              // n张地毯
int xb, yb, xe, ye; // 起点终点坐标
int x_0, y_0;       // 所求点坐标
stack<Node> st;     // 栈
Node node;          // 节点
int cnt = 0;        // 计数器
int ans = 0;        // 答案

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while (n--) {
        cin >> node.a >> node.b >> node.g >> node.k;
        st.push(node);
        cnt++;
    }
    cin >> x_0 >> y_0;

    while (!st.empty()) {
        node = st.top();
        st.pop();
        if (x_0 >= node.a && x_0 <= node.a + node.g && y_0 >= node.b &&
            y_0 <= node.b + node.k) {
            break;
        } else {
            cnt--;
        }
    }

    if (cnt == 0) {
        cout << -1;
    } else {
        cout << cnt;
    }

    return 0;
}