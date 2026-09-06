#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 5;
struct I {
    int l;
    int r;
    int sum;
    int sum2;
} tree[4 * N];
int n, m;
int w[N];
int ksm(int a, int b, int id) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % id;
        a = a * a % id;
        b >>= 1;
    }
    return res;
}

void pushup(int id) {
    tree[id].sum = (tree[id * 2].sum + tree[id * 2 + 1].sum) % mod;
    tree[id].sum2 = (tree[id * 2].sum2 + tree[id * 2 + 1].sum2) % mod;
}

void update(int id, int l, int r, int k) {
    if (l <= tree[id].l && tree[id].r <= r) {
        tree[id].sum = k % mod;
        tree[id].sum2 = (k % mod) * (k % mod);
        return;
    }
    int m = tree[id].l + tree[id].r >> 1;
    if (l <= m) update(id * 2, l, r, k);
    if (r > m) update(id * 2 + 1, l, r, k);
    pushup(id);
}

pair<int, int> query(int id, int l, int r) {
    int res = 0, res2 = 0;
    if (l <= tree[id].l && tree[id].r <= r) {
        return {tree[id].sum, tree[id].sum2};
    }
    int m = tree[id].l + tree[id].r >> 1;
    if (l <= m) {
        auto [x, s2] = query(id * 2, l, r);
        res = (res + x) % mod;
        res2 = (res2 + s2) % mod;
    }
    if (r > m) {
        auto [x, s2] = query(id * 2 + 1, l, r);
        res = (res + x) % mod;
        res2 = (res2 + s2) % mod;
    }
    return {res, res2};
}

void build(int id, int l, int r) {
    tree[id] = {l, r, w[l] % mod, (w[l] % mod) * (w[l] % mod)};
    if (l == r) return;
    int m = l + r >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    pushup(id);
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            int x = query(1, l, r).first;
            int s2 = query(1, l, r).second;
            int avg = (x % mod) * ksm(len, mod - 2, mod) % mod;
            int var = (s2 - ((x * x % mod) * ksm(len, mod - 2, mod)) % mod + mod) % mod;
            cout << avg << " " << var << "\n";
        } else if (op == 2) {
            int k, l;
            cin >> k >> l;
            update(1, k, k, l);
        }
    }
    return 0;
}