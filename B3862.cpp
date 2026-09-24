#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 1005;

int n, t;
vector<int> g[N];
bool vis[N];

void dfs(int x) {
    for (int i : g[x]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> t;
    int u, v;
    for (int i = 1; i <= t; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = true;
        dfs(i);
        int ans = -1;
        for (int j = 1; j <= n; j++)
            if (vis[j]) ans = j;
        cout << ans << ' ';
        memset(vis, 0, sizeof vis);
    }
    return 0;
}