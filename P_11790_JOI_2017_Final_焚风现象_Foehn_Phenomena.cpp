#include <bits/stdc++.h>

#define lowbit(x) x & -x
#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 200005;

i64 n, q, s, t, ans, a[N];

struct bit {

    int tree[N];

    void update(int x, i64 sum) {
        while (x <= n) {
            tree[x] += sum;
            x += lowbit(x);
        }
    }

    void add(int l, int r, i64 sum) {
        update(l, sum);
        if (r + 1 <= n) update(r + 1, -sum);
    }

    i64 query(int x) {
        i64 res = 0;
        while (x) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }

} tree;

int tot(int x) { return a[x] + (x == 0 ? 0 : tree.query(x)); }

int sum(int x) {
    i64 res = tot(x + 1) - tot(x);
    return res > 0 ? -res * s : -res * t;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> q >> s >> t;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        ans += sum(i);
    i64 l, r, x;
    while (q--) {
        cin >> l >> r >> x;
        ans -= sum(l - 1);
        if (r < n) ans -= sum(r);
        tree.add(l, r, x);
        ans += sum(l - 1);
        if (r < n) ans += sum(r);
        cout << ans << endl;
    }
    return 0;
}
