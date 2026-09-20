#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> tr(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &tr[i].first, &tr[i].second);

    while (m--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int cnt = 0;
        for (auto& p : tr)
            if (a <= p.first && p.first <= c && b <= p.second && p.second <= d) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}