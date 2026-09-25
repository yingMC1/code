#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 2e5 + 5;

int n, num[3], vis[N];
vector<int> g[N];

void dfs(int x, int cnt) {
    if (cnt % 2 == 0) {
        num[2]++;
        vis[x] = 2;
    } else {
        num[1]++;
        vis[x] = 1;
    }
    for (int i : g[x])
        if (!vis[i]) dfs(i, cnt + 1);
}

int main() {
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << num[vis[i]] << ' ';
    return 0;
}