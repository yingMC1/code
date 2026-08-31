#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 2e3 + 5;

int n, m;
string x;
i64 sum;
bool f, t1[N][N];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            string t;
            cin >> t;
            if (t == x)
                t1[i][j] = true;
            else if (t == "L")
                f = true;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            if (t1[i][j] || f) sum += t;
        }
    cout << sum;
    return 0;
}