#include <bits/stdc++.h>

#define lowbit(x) x & -x
using namespace std;
using i64 = long long;
const int N = 1e4 + 5;

int t, n, W, H, tot;
i64 b[N * 3], tree[N * 4], tag[N * 4];

struct I {
    i64 x, y, l;
} a[N * 2];

void update(int p, int l, int r, int ql, int qr, i64 w) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        tree[p] += w;
        tag[p] += w;
        return;
    }
    int mid = (l + r) / 2;
    update(p * 2, l, mid, ql, qr, w);
    update(p * 2 + 1, mid + 1, r, ql, qr, w);
    tree[p] = tag[p] + max(tree[p * 2], tree[p * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> t;
    int x, y, l;
    for (int i = 1; i <= t; i++) {
        tot = 0;
        cin >> n >> W >> H;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> l;
            b[++tot] = y - H;
            b[++tot] = y;
            a[i] = {x - W, y, l};
            a[i + n] = {x, y, -l};
        }
        sort(b + 1, b + tot + 1);
        tot = unique(b + 1, b + tot + 1) - (b + 1);
        sort(a + 1, a + n * 2 + 1, [&](I x, I y) { return x.x < y.x; });
        fill(tree, tree + 4 * N, 0);
        fill(tag, tag + 4 * N, 0);

        i64 ans = 0;
        for (int i = 0; i < 2 * n;) {
            int j = i;
            while (j < 2 * n && a[j].x == a[i].x) {
                int l = lower_bound(b + 1, b + tot + 1, a[j].y - H) - b + 1;
                int r = lower_bound(b + 1, b + tot + 1, a[j].y) - b;
                update(1, 1, tot, l, r, a[j].l);
                j++;
            }
            ans = max(ans, tree[1]);
            i = j;
        }
        cout << ans << '\n';
    }
    return 0;
}