#include <bits/stdc++.h>

#define lowbit(x) x & -x
using namespace std;
using i64 = long long;
const int N = 1e6 + 5;

int n, m, tot;
i64 b[N * 5], tree[N], ans[N];

struct J {
    i64 x, y, p;
} a[N];

struct Q {
    i64 x, y;
    int op, id;
} q[N * 4];

void update(int x, i64 v) {
    while (x <= tot) {
        tree[x] += v;
        x += lowbit(x);
    }
}

i64 query(int x) {
    i64 res = 0;
    while (x > 0) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].p;
        b[++tot] = a[i].y;
    }
    i64 x1, y1, x2, y2;
    for (int i = 1; i <= m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        q[4 * i - 3] = {x2, y2, 1, i};
        q[4 * i - 2] = {x1 - 1, y2, -1, i};
        q[4 * i - 1] = {x2, y1 - 1, -1, i};
        q[4 * i] = {x1 - 1, y1 - 1, 1, i};
        b[++tot] = y1;
        b[++tot] = y2;
    }
    sort(a + 1, a + n + 1, [](const J& a, const J& b) { return a.x < b.x; });
    sort(q + 1, q + 4 * m + 1, [](const Q& a, const Q& b) { return a.x < b.x; });
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i].y = lower_bound(b + 1, b + tot + 1, a[i].y) - b;
    }
    for (int i = 1; i <= 4 * m; i++) {
        q[i].y = upper_bound(b + 1, b + tot + 1, q[i].y) - b - 1;
    }
    int now = 1;
    for (int i = 1; i <= 4 * m; i++) {
        while (now <= n && a[now].x <= q[i].x) {
            update(a[now].y, a[now].p);
            now++;
        }
        ans[q[i].id] += q[i].op * query(q[i].y);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}