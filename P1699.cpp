#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 15;

int bx, by, ex, ey, ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<tuple<int, int, int>> q;
bool vis[N][N];
char c;

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> c;
            if (c == 'L')
                bx = i, by = j;
            else if (c == 'B')
                ex = i, ey = j;
            else if (c == 'R')
                vis[i][j] = true;
        }
    }
    q.push({bx, by, 0});
    while (!q.empty()) {
        auto [x, y, u] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            cout << u - 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 10 || 1 > nx || ny > 10 || 1 > ny || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny, u + 1});
        }
    }
}