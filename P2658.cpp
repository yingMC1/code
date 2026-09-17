#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 505;

int n, m, a[N][N], b[N][N], tot;
bool vis[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool chack(int mid) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 1; j <= m; j++)
            if (b[i][j]) {
                q.push({i, j});
                vis[i][j] = true;
                flag = true;
                break;
            }
        if (flag) break;
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt += b[x][y];
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) continue;
            if (abs(a[x][y] - a[xx][yy]) > mid) continue;
            vis[xx][yy] = true;
            q.push({xx, yy});
        }
    }
    return cnt == tot;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j], tot += b[i][j];
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = l + r >> 1;
        if (chack(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
}