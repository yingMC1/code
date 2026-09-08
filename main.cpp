#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int N = 1e5 + 5;

struct I {
    int sum;
    int sum2;
} tree[4 * N];
int n, m, b[N];

int ksm(int a, int b, int id) {
    long long res1 = 1;
    while (b) {
        if (b & 1) res1 = res1 * a % id;
        a = 1LL * a * a % id;
        b >>= 1;
    }
    return (int)res1;
}

void up(int id) {
    tree[id].sum = (tree[id * 2].sum + tree[id * 2 + 1].sum) % mod;
    tree[id].sum2 = (tree[id * 2].sum2 + tree[id * 2 + 1].sum2) % mod;
}

void build(int x, int l, int r) {
    if (l == r) {
        tree[x].sum = b[l];
        tree[x].sum2 = 1LL * b[l] * b[l] % mod;
        return;
    }
    int mid = l + r >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    up(x);
}

void update(int x, int l, int r, int q, int w) {
    if (l == r) {
        tree[x].sum = w;
        tree[x].sum2 = 1LL * w * w % mod;
        return;
    }
    int mid = l + r >> 1;
    if (q <= mid)
        update(x * 2, l, mid, q, w);
    else
        update(x * 2 + 1, mid + 1, r, q, w);
    up(x);
}

pair<int, int> query(int id, int l, int r, int ql, int qr) {
    int res1 = 0, res2 = 0;
    if (ql <= l && r <= qr) {
        return {tree[id].sum, tree[id].sum2};
    }
    int mid = l + r >> 1;
    if (ql <= mid) {
        auto [x, y] = query(id * 2, l, mid, ql, qr);
        res1 = (res1 + x) % mod;
        res2 = (res2 + y) % mod;
    }
    if (qr > mid) {
        auto [x, y] = query(id * 2 + 1, mid + 1, r, ql, qr);
        res1 = (res1 + x) % mod;
        res2 = (res2 + y) % mod;
    }
    return {res1, res2};
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    build(1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
            update(1, 1, n, l, r);
        else if (op == 2) {
            int len = r - l + 1;
            int x = query(1, 1, n, l, r).first;
            int y = query(1, 1, n, l, r).second;
            int inv = ksm(len, mod - 2, mod);
            int ans =
                (1LL * (1LL * y * len % mod - 1LL * x * x % mod + mod) * inv % mod * inv) % mod;
            cout << ans << endl;
        }
    }
    return 0;
}