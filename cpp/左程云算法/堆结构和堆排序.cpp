// https://luogu.com.cn/problem/P
// 堆结构
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n;
int arr[N];
int size = 0;

void heap_insert(int x) { // 插入节点
    int idx = size;
    arr[size++] = x;
    int fa = (idx - 1) / 2;

    while (arr[idx] > arr[fa]) {
        swap(arr[fa], arr[idx]);
        idx = fa;
        fa = (idx - 1) / 2;
    }
}
void heapfy(int x) { // 替换top节点
    int idx = 0;
    arr[idx] = x;
    int lchil = idx * 2 + 1;
    int rchil = idx * 2 + 2;

    while (1) {
        int lchil = idx * 2 + 1;
        int rchil = idx * 2 + 2;
        int largest = idx;

        if (lchil < size && arr[lchil] > arr[largest]) {
            largest = lchil;
        }
        if (rchil < size && arr[rchil] > arr[largest]) {
            largest = rchil;
        }

        if (idx == largest) {
            break;
        }
        swap(arr[largest], arr[idx]);
        idx = largest;
    }
}

void solve() {
    size = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        heap_insert(temp);
    }
    heapfy(4);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapfy(0);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heap_sort();

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}