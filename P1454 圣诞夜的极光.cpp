#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 105;

int n, m, ans;
char c[N][N];
const int nx[13] = {0, 1,-1, 0, 0, 2,-2, 0, 0, 1,-1, 1,-1};
const int ny[13] = {0, 0, 0, 1,-1, 0, 0, 2,-2,-1, 1, 1,-1};

void dfs(int x, int y){
    if (x < 1 || n < x || y < 1 || m < y || c[x][y] !=  '#')return;
    c[x][y] = '-';
    for (int i = 1; i <= 12; i++)dfs(x + nx[i], y + ny[i]);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (c[i][j] ==  '#'){
                ans++;
                dfs(i, j);
            }
    cout << ans << endl;
    return 0;
}