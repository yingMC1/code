#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 2e5 + 5;

int n;
vector<int> g[N];

int main() {
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return 0;
}