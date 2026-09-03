#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 105;

int n, m, t, dp[N * 2][2];

struct I {
    int m, t;
} a[N];

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i].m >> a[i].t;
    for (int i = 1; i <= n; i++) {
        dp[i][1] =
    }
}