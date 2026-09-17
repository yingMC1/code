#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 1e6 + 5;

int n, tot, ans;

struct I {
    int x1, x2, h, w;
} a[N * 2];

int tree[N * 8], tag[N * 8], b[N * 4], len[N * 8];

void push_up(int x, int l, int r) {
    if (tree[x])
        len[x] = b[r + 1] - b[l];
    else if (l == r)
        len[x] = 0;
    else
        len[x] = len[x * 2] + len[x * 2 + 1];
}

void update(int x, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
        tree[x] += w;
        push_up(x, l, r);
        return;
    }
    int mid = l + r >> 1;
    if (ql <= mid) update(x * 2, l, mid, ql, qr, w);
    if (qr > mid) update(x * 2 + 1, mid + 1, r, ql, qr, w);
    push_up(x, l, r);
}

bool cmp(I x, I y) { return x.h < y.h; }

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, x2, y1, 1};
        a[i + n] = {x1, x2, y2, -1};
        b[++tot] = x1;
        b[++tot] = x2;
    }
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - (b + 1);
    sort(a + 1, a + n * 2 + 1, cmp);
    for (int i = 1; i <= n * 2; i++) {
        a[i].x1 = lower_bound(b + 1, b + tot + 1, a[i].x1) - b;
        a[i].x2 = lower_bound(b + 1, b + tot + 1, a[i].x2) - b;
        ans += (a[i].h - a[i - 1].h) * len[1];
        update(1, 1, tot - 1, a[i].x1, a[i].x2 - 1, a[i].w);
    }
    cout << ans << endl;
    return 0;
}