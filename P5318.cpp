#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 5;

vector<int> g[N];
bool vis[N];
int n, m;

void dfs(int x) {
    cout << x << ' ';
    for (int i : g[x]) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i);
    }
}

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i : g[x]) {
            if (vis[i]) continue;
            vis[i] = true;
            q.push(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());

    memset(vis, 0, sizeof vis);
    vis[1] = true;
    dfs(1);
    cout << endl;

    memset(vis, 0, sizeof vis);
    bfs();
    return 0;
}