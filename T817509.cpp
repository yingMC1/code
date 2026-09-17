#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 1005;

int n, maxx = INT_MAX, f[N], ans[N];
vector<int> g[N];
bool v[N];

void dfs1(int x) {}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }

    return 0;
}