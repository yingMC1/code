#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 100005;

i64 n, m, a[N], tag1[N << 2], tag2[N << 2];

void push_down(int x, int l, int r) {
    if (!tag1[x] && !tag2[x]) return;
    int mid = l + r >> 1;
    tag1[x * 2] += tag1[x];
    tag2[x * 2] += tag2[x];
    tag1[x * 2 + 1] += tag1[x] + (mid - l + 1) * tag2[x];
    tag2[x * 2 + 1] += tag2[x];
    tag1[x] = tag2[x] = 0;
}

void update(int x, int l, int r, int ql, int qr, int k, int d) {
    if (ql <= l && r <= qr) {
        tag1[x] += k + (l - ql) * d;
        tag2[x] += d;
        return;
    }
    push_down(x, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) update(x * 2, l, mid, ql, qr, k, d);
    if (qr > mid) update(x * 2 + 1, mid + 1, r, ql, qr, k, d);
}

i64 query(int x, int l, int r, int q) {
    if (l == r) return tag1[x] + a[l];
    push_down(x, l, r);
    int mid = l + r >> 1;
    if (q <= mid)
        return query(x * 2, l, mid, q);
    else
        return query(x * 2 + 1, mid + 1, r, q);
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int op, l, r, k, d;
    while (m--) {
        cin >> op >> l;
        if (op == 1) {
            cin >> r >> k >> d;
            update(1, 1, n, l, r, k, d);
        } else
            cout << query(1, 1, n, l) << endl;
    }
}