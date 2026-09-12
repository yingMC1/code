#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
const int N = 1e6 + 5;

int n, c, m, a[N], tree[N << 2], tag[N << 2], last[N], llast[N], ql[N], qr[N], ans[N];
vector<int> qrt[N];

void push_up(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }

void down(int x, int w) {
    tree[x] += w;
    tag[x] += w;
}

void push_down(int x) {
    if (!tag[x]) return;
    down(x * 2, tag[x]);
    down(x * 2 + 1, tag[x]);
    tag[x] = 0;
}

void update(int x, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
        down(x, w);
        return;
    }
    push_down(x);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(x * 2, l, mid, ql, qr, w);
    if (qr > mid) update(x * 2 + 1, mid + 1, r, ql, qr, w);
    push_up(x);
}

int query(int x, int l, int r, int pos) {
    if (l == r) return tree[x];
    push_down(x);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return query(x * 2, l, mid, pos);
    else
        return query(x * 2 + 1, mid + 1, r, pos);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> c >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> ql[i] >> qr[i];
        qrt[qr[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (last[a[i]]) update(1, 1, n, llast[a[i]] + 1, last[a[i]], 1);
        llast[a[i]] = last[a[i]];
        last[a[i]] = i;
        for (int x : qrt[i])
            ans[x] = query(1, 1, n, ql[x]);
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}