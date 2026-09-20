#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int n, m, dep[N], ans;
bool vis[N];
vector<int> g[N];

void dfs(int x) {
    vis[x] = true;
    dep[x] = 1;
    for (int i : g[x]) {
        if (vis[i]) continue;
        dfs(i);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (dep[i] == 0) dfs(i), ans++;
    cout << ans - 1;
    return 0;
}