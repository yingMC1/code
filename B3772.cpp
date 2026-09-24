#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 120;

int n, m, k, dis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
char g[N][N];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = '.';
            dis[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i + k][j + k];
    for (int i = 0; i < n + 2 * k; i++)
        for (int j = 0; j < m + 2 * k; j++)
            if (g[i][j] == '#') {
                dis[i][j] = 0;
                q.push({i, j});
            }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (dis[x][y] == k) continue;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n + 2 * k || ny >= m + 2 * k) continue;
            if (dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n + 2 * k; i++)
        for (int j = 0; j < m + 2 * k; j++)
            if (dis[i][j] != -1 && g[i][j] == '.') ans++;
    cout << ans << '\n';
    return 0;
}