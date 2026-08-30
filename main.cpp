#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;
const int INF = 1e9;

int n, m, a[N], tree[N << 2], mi[N << 2];

void up(int x) {
    int lc = x * 2, rc = x * 2 + 1;
    if (tree[lc] < tree[rc]) {
        tree[x] = tree[lc];
        mi[x] = mi[lc];
    } else if (tree[lc] > tree[rc]) {
        tree[x] = tree[rc];
        mi[x] = mi[rc];
    } else {
        tree[x] = tree[lc];
        mi[x] = min(mi[lc], mi[rc]);
    }
}

void build(int x, int l, int r) {
    if (l == r) {
        tree[x] = a[l];
        mi[x] = l;
        return;
    }
    int mid = l + r >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    up(x);
}

void update(int x, int l, int r, int p, int w) {
    if (l == r) {
        tree[x] = a[l] = w;
        mi[x] = p;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid)
        update(x * 2, l, mid, p, w);
    else
        update(x * 2 + 1, mid + 1, r, p, w);
    up(x);
}

int weizhi(int x, int l, int r, int pos) {
    if (l == r)
        return tree[x];
    int mid = l + r >> 1;
    if (pos <= mid)
        return weizhi(x * 2, l, mid, pos);
    else
        return weizhi(x * 2 + 1, mid + 1, r, pos);
}

int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return mi[x];
    }
    int mid = l + r >> 1;
    int ans = -INF;
    int res = INF;
    if (ql <= mid) {
        int ti = query(x * 2, l, mid, ql, qr);
        int t = weizhi(1, 1, n, ti);
        if (t < res || (t == res && ti < ans)) {
            res = t;
            ans = ti;
        }
    }
    if (qr > mid) {
        int ti = query(x * 2 + 1, mid + 1, r, ql, qr);
        int t = weizhi(1, 1, n, ti);
        if (t < res || (t == res && ti < ans)) {
            res = t;
            ans = ti;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'C')
            update(1, 1, n, l, r);
        else
            cout << query(1, 1, n, l, r) << endl;
    }
    return 0;
}