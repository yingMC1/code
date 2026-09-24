#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 105;

int n, m;
bool b[N][N];

int main() {
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '#') {
                if (1 <= j - 2) b[i][j - 2] = true;
                if (1 <= j - 1) b[i][j - 1] = true;
                if (j + 2 <= m) b[i][j + 2] = true;
                if (j + 1 <= m) b[i][j + 1] = true;
                if (1 <= i - 2) b[i - 2][j] = true;
                if (1 <= i - 1) b[i - 1][j] = true;
                if (i + 2 <= n) b[i + 2][j] = true;
                if (i + 1 <= n) b[i + 1][j] = true;
                if (i + 1 <= n && j + 1 <= m) b[i + 1][j + 1] = true;
                if (i - 1 <= n && j + 1 <= m) b[i - 1][j + 1] = true;
                if (i + 1 <= n && j - 1 <= m) b[i + 1][j - 1] = true;
                if (i - 1 <= n && j - 1 <= m) b[i - 1][j - 1] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}