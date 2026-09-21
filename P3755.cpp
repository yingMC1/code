#include <bits/stdc++.h>

#define lowbit(x) x & -x
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, m, tot;
i64 b[N * 7], tree[N], ans[N];

struct 基站 {
    i64 x, y, l;
} a[N];

struct 查询 {
    i64 x1, x2, y, op, id;
} q[N * 2];

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].l;
        b[++tot] = a[i].x;
        b[++tot] = a[i].y;
        b[++tot] = a[i].l;
    }
    int x1, x2, y1, y2;
    for (int i = 1; i <= m; i++) {
        cin >> x1 >> x2 >> y1 >> y2;
        q[i] = {x1, x2, y1, 1, i};
        q[i + m] = {x1, x2, y2, -1, i};
        b[++tot] = x1;
        b[++tot] = x2;
        b[++tot] = y1;
        b[++tot] = y2;
    }
    sort(a + 1, a + n + 1, [](const 基站& a, const 基站& b) { return a.l < b.l; });
    sort(q + 1, q + 2 * m + 1, [](const 查询& a, const 查询& b) { return a.y < b.y; });
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i].x = lower_bound(b + 1, b + tot + 1, a[i].x) - b;
        a[i].y = lower_bound(b + 1, b + tot + 1, a[i].y) - b;
        a[i].l = lower_bound(b + 1, b + tot + 1, a[i].l) - b;
    }
    for (int i = 1; i <= 2 * m; i++) {
        q[i].x1 = lower_bound(b + 1, b + tot + 1, q[i].x1) - b;
        q[i].x2 = lower_bound(b + 1, b + tot + 1, q[i].x2) - b;
        q[i].y = lower_bound(b + 1, b + tot + 1, q[i].y) - b;
    }
    int now = 1;
    for (int i = 1; i <= 2 * m; i++) {
        while (now <= n && a[now].l <= q[i].y) {
            update(a[now].x, 1);
            now++;
        }
        ans[q[i].id] += q[i].op * (query(q[i].x2) - query(q[i].x1 - 1)) * 1LL;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}