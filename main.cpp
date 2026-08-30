#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;
using i64   = long long;
const int N = 1e5 + 5;

i64 n, m, a[N], tree[N << 2], tag[N << 2];

void down_sum(int x, int l, int r, int w) {
    tree[x] += w * (r - l + 1);
    tag[x] += w;
}

void down(int x, int l, int r) {
    if(!tag[x])
        return;
    int mid = l + r >> 1;
    down_sum(x * 2, l, mid, tag[x]);
    down_sum(x * 2 + 1, mid + 1, r, tag[x]);
    tag[x] = 0;
}

void push_up(int x) { tree[x] = tree[N * 2] + tree[N * 2 + 1]; }

void build(int x, int l, int r) {
    if(l == r) {
        tree[x] += a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    push_up(x);
}

void update(int x, int l, int r, int ql, int qr, int w) {
    if(ql <= l && r <= qr) {
        tree[x] += w * (r - l + 1);
        tag[x] += w;
        return;
    }
    down(x, l, r);
    int mid = l + r >> 1;
    if(ql <= mid)
        update(x * 2, l, mid, ql, qr, w);
    if(qr > mid)
        update(x * 2 + 1, mid + 1, r, ql, qr, w);
    push_up(x);
}

int query(int x, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr)
        return tree[x];
    down(x, l, r);
    int mid = l + r >> 1, res = 0;
    if(ql <= mid)
        res += query(x * 2, l, mid, ql, qr);
    if(qr > mid)
        res += query(x * 2 + 1, mid + 1, r, ql, qr);
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        char c;
        int  l, r;
        cin >> c >> l >> r;
        if(c == 'C') {
            int x;
            cin >> x;
            update(1, 1, n, l, r, x);
        } else
            cout << query(1, 1, n, l, r) << endl;
    }
    return 0;
}