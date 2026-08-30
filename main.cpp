#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;
const int INF = 2e9;

int n, q, a[N];

struct I {
    int sum, l, r, len;
} tree[N << 2];

I push_up(I l, I r) {
    I res;
    res.len = l.len + r.len;
    res.sum = l.sum;
    if (l.sum == l.len)
        res.sum += r.sum;
    res.l = r.l;
    if (r.l == r.len)
        res.l += l.l;
    res.r = max({l.r, r.r, l.l + r.sum});
    return res;
}

void build(int x, int l, int r) {
    if (l == r) {
        tree[x].len = 1;
        tree[x].sum = tree[x].l = tree[x].r = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    tree[x] = push_up(tree[x * 2], tree[x * 2 + 1]);
}

I query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[x];
    }
    int mid = l + r >> 1;
    if (qr <= mid)
        return query(x * 2, l, mid, ql, qr);
    if (ql > mid)
        return query(x * 2 + 1, mid + 1, r, ql, qr);
    I l2 = query(x * 2, l, mid, ql, qr);
    I r2 = query(x * 2 + 1, mid + 1, r, ql, qr);
    return push_up(l2, r2);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r).r << endl;
    }
    return 0;
}