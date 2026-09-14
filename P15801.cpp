#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, l[N], r[N], ans;
i64 dp[N];
bool vis1[N], vis2[N];

void dfs(int x) {
    if (!x) {
        vis1[x] = 1;
        vis2[x] = 1;
        return;
    }
    dfs(l[x]);
    dfs(r[x]);
    dp[x] = max(dp[l[x]], dp[r[x]]) + 1;
    vis1[x] = vis1[l[x]] && vis1[r[x]] && dp[l[x]] == dp[r[x]];
    if (dp[l[x]] == dp[r[x]]) vis2[x] = vis1[l[x]] && vis2[r[x]];
    if (dp[l[x]] == dp[r[x]] + 1) vis2[x] = vis1[r[x]] && vis2[l[x]];
    if (vis2[x]) ans++;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    dfs(1);
    cout << ans;
    return 0;
}
