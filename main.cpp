#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;
double tag[N << 2], tree[N << 2], sum[N << 2], a[N];

void push_up(int id) {
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

void down(int id, int l, int r, double w) {
    double len = r - l + 1;
    sum[id] += 2 * w * tree[id] + len * w * w;
    tree[id] += w * len;
    tag[id] += w;
}

void push_down(int id, int l, int r) {
    if (!tag[id]) return;
    int mid = l + r >> 1;
    down(id * 2, l, mid, tag[id]);
    down(id * 2 + 1, mid + 1, r, tag[id]);
    tag[id] = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        sum[id] = a[l] * a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    push_up(id);
}

void update(int id, int l, int r, int ql, int qr, double w) {
    if (ql <= l && r <= qr) {
        down(id, l, r, w);
        return;
    }
    push_down(id, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) update(id * 2, l, mid, ql, qr, w);
    if (qr > mid) update(id * 2 + 1, mid + 1, r, ql, qr, w);
    push_up(id);
}

double query1(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[id];
    push_down(id, l, r);
    int mid = l + r >> 1;
    double res = 0;
    if (ql <= mid) res += query1(id * 2, l, mid, ql, qr);
    if (qr > mid) res += query1(id * 2 + 1, mid + 1, r, ql, qr);
    return res;
}

double query2(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[id];
    push_down(id, l, r);
    int mid = l + r >> 1;
    double res = 0;
    if (ql <= mid) res += query2(id * 2, l, mid, ql, qr);
    if (qr > mid) res += query2(id * 2 + 1, mid + 1, r, ql, qr);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int op;
    double l, r, k;
    for (int i = 1; i <= m; i++) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> k;
            update(1, 1, n, l, r, k);
        } else if (op == 2) {
            double len = r - l + 1;
            double ans = query1(1, 1, n, l, r) / len;
            printf("%.4lf\n", ans);
        } else {
            double len = r - l + 1;
            double res = query1(1, 1, n, l, r) / len;
            double ans = query2(1, 1, n, l, r) / len - res * res;
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}