#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int mod = 1000000007;
const int N = 2005;

i64 n, sz[N], dp[N][N][3], f[N][3];
vector<int> g[N];

void dfs(int x, int fa) {
    dp[x][0][2] = 1;
    dp[x][1][0] = 1;
    sz[x] = 1;
    for (int i : g[x]) {
        if (i == fa) continue;
        dfs(i, x);
        memset(f, 0, sizeof(f));
        for (int j = 0; j <= sz[x]; j++) {
            for (int k = 0; k <= sz[i]; k++) {
                for (int l = 0; l < 3; l++) {
                    if (dp[x][j][l] == 0) continue;
                    for (int m = 0; m < 3; m++) {
                        if (dp[i][k][m] == 0) continue;
                        int cnt1 = j + k, cnt2;
                        if (l == 2 && m == 0) cnt1++;
                        if (l == 0 && m == 2) cnt1++;
                        if (l == 0)
                            cnt2 = 0;
                        else if (l == 1)
                            cnt2 = 1;
                        else if (m == 0)
                            cnt2 = 1;
                        else
                            cnt2 = 2;
                        f[cnt1][cnt2] = (f[cnt1][cnt2] + dp[x][j][l] * dp[i][k][m]) % mod;
                    }
                }
            }
        }
        sz[x] = sz[x] + sz[i];
        for (int j = 0; j <= sz[x]; j++) {
            dp[x][j][0] = f[j][0];
            dp[x][j][1] = f[j][1];
            dp[x][j][2] = f[j][2];
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp, 0, sizeof(dp));
    dfs(1, 0);
    for (int i = 0; i <= n; i++) {
        i64 ans = (dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % mod;
        cout << ans << endl;
    }
    return 0;
}