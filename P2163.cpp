#include <bits/stdc++.h>

#define lowbit(x) (x) & (-x)
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;

int n, m, tree[N], b[N * 6], tot, ans[N];

struct I {
    int x, y;
} a[N];

struct J {
    int x1, x2, h, op, w;
} c[N * 2];

void update(int x, int w) {
    while (x <= tot) {
        tree[x] += w;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        b[++tot] = a[i].x;
        b[++tot] = a[i].y;
    }
    sort(a + 1, a + n + 1, [&](I x, I y) { return x.y < y.y; });
    for (int i = 1; i <= m; i++) {
        int a1, b1, c1, d1;
        cin >> a1 >> b1 >> c1 >> d1;
        a1--, b1--;
        c[i] = {a1, c1, b1, -1, i};
        c[i + m] = {a1, c1, d1, 1, i};
        b[++tot] = c[i].x1;
        b[++tot] = c[i].x2;
        b[++tot] = c[i].h;
        b[++tot] = c[i + m].h;
    }
    sort(c + 1, c + m * 2 + 1, [&](J x, J y) { return x.h < y.h; });
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - (b + 1);
    for (int i = 1; i <= m * 2; i++) {
        c[i].x1 = lower_bound(b + 1, b + tot + 1, c[i].x1) - b;
        c[i].x2 = lower_bound(b + 1, b + tot + 1, c[i].x2) - b;
        c[i].h = lower_bound(b + 1, b + tot + 1, c[i].h) - b;
    }
    for (int i = 1; i <= n; i++) {
        a[i].x = lower_bound(b + 1, b + tot + 1, a[i].x) - b;
        a[i].y = lower_bound(b + 1, b + tot + 1, a[i].y) - b;
    }
    int now = 1;
    for (int i = 1; i <= m * 2; i++) {
        while (now <= n && a[now].y <= c[i].h) {
            update(a[now].x, 1);
            now++;
        }
        ans[c[i].w] += c[i].op * (query(c[i].x2) - query(c[i].x1));
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}