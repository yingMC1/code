#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 105;

int n, M, T, m[N], t[N], dp[N * 2][2];

int main() {
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++)
        cin >> m[i] >> t[i];
    for (int i = 1; i <= n; i++) {
        for (int j = M; j >= m[i]; j--) {
            if (dp[j - m[i]][0] + t[i] <= T) {
                dp[j][0] = max(dp[j][0], dp[j - m[i]][0] + t[i]);
                dp[j][1] = max(dp[j][1], dp[j - m[i]][1] + 1);
            }
        }
    }
    cout << dp[M][1] << endl;
}