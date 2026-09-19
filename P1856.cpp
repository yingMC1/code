#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 1e6 + 5;

int n, tot;

struct I {
    int x1, x2, h, w;
} a[N * 2], c[N * 2];

int tree[N * 8], b[N * 4], len[N * 8], tag[N * 8];
int x[N * 4], y[N * 4];
bool vis1[N * 8], vis2[N * 8];

void push_up(int x, int l, int r) {
    if (tree[x]) {
        len[x] = b[r + 1] - b[l];
        tag[x] = 1;
        vis1[x] = vis2[x] = true;
    } else if (l == r) {
        len[x] = 0;
        tag[x] = 0;
        vis1[x] = vis2[x] = false;
    } else {
        len[x] = len[x * 2] + len[x * 2 + 1];
        tag[x] = tag[x * 2] + tag[x * 2 + 1] - (vis2[x * 2] && vis1[x * 2 + 1]);
        vis1[x] = vis1[x * 2];
        vis2[x] = vis2[x * 2 + 1];
    }
}

void update(int x, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
        tree[x] += w;
        push_up(x, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) update(x * 2, l, mid, ql, qr, w);
    if (qr > mid) update(x * 2 + 1, mid + 1, r, ql, qr, w);
    push_up(x, l, r);
}

bool cmp(I x, I y) {
    if (x.h != y.h) return x.h < y.h;
    return x.w > y.w;
}

int calc(I* e, int* c) {
    sort(c + 1, c + 2 * n + 1);
    tot = unique(c + 1, c + 2 * n + 1) - (c + 1);
    copy(c + 1, c + tot + 1, b + 1);
    memset(tree, 0, sizeof tree);
    memset(len, 0, sizeof len);
    memset(tag, 0, sizeof tag);
    memset(vis1, 0, sizeof vis1);
    memset(vis2, 0, sizeof vis2);
    sort(e + 1, e + 2 * n + 1, cmp);
    for (int i = 1; i <= 2 * n; i++) {
        e[i].x1 = lower_bound(b + 1, b + tot + 1, e[i].x1) - b;
        e[i].x2 = lower_bound(b + 1, b + tot + 1, e[i].x2) - b;
    }

    int result = 0;
    int previous_height = e[1].h;
    for (int i = 1; i <= 2 * n; i++) {
        result += 2 * tag[1] * (e[i].h - previous_height);
        update(1, 1, tot - 1, e[i].x1, e[i].x2 - 1, e[i].w);
        previous_height = e[i].h;
    }
    return result;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, x2, y1, 1};
        a[i + n] = {x1, x2, y2, -1};
        c[i] = {y1, y2, x1, 1};
        c[i + n] = {y1, y2, x2, -1};
        x[2 * i - 1] = x1;
        x[2 * i] = x2;
        y[2 * i - 1] = y1;
        y[2 * i] = y2;
    }
    cout << calc(a, x) + calc(c, y) << endl;
    return 0;
}
