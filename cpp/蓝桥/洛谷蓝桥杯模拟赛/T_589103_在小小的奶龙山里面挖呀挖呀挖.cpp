#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 50005;
const int MAXA = 100005;

vector<int> tree[MAXN];
int a[MAXN];
int depth[MAXN];
int parent[MAXN];
unordered_map<int, int> factor_count[MAXN];
bool visited[MAXN];
vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAXA, true);
    for (int i = 2; i < MAXA; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < MAXA; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void get_factors(int number, unordered_map<int, int> &factors) {
    for (int prime : primes) {
        if (prime * prime > number)
            break;
        while (number % prime == 0) {
            factors[prime]++;
            number /= prime;
        }
    }
    if (number > 1) {
        // number itself is a prime
        factors[number]++;
    }
}

void dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    // Get the prime factors of a[node]
    unordered_map<int, int> current_factors;
    get_factors(a[node], current_factors);

    // Update factor_count for this node
    factor_count[node] = current_factors;

    for (int child : tree[node]) {
        if (child != par) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
            // Merge child's factors into current node's factors
            for (auto &p : factor_count[child]) {
                factor_count[node][p.first] += p.second;
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Setup DFS to calculate depth and parent
    depth[1] = 0;
    dfs(1, -1);

    // Handle each query
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        int lca_node = lca(u, v);
        unordered_map<int, int> total_factors;

        for (int cur = u; cur != lca_node; cur = parent[cur]) {
            for (auto &p : factor_count[cur]) {
                total_factors[p.first] += p.second;
            }
        }
        for (int cur = v; cur != lca_node; cur = parent[cur]) {
            for (auto &p : factor_count[cur]) {
                total_factors[p.first] += p.second;
            }
        }

        // Include LCA node
        for (auto &p : factor_count[lca_node]) {
            total_factors[p.first] += p.second;
        }

        // Count unique companies (unique prime factors)
        cout << total_factors.size() << "\n";
    }

    return 0;
}
