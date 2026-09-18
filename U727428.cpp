#include <bits/stdc++.h>

#define int long long
#define lowbit(x) x & -x
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, tree[N];

void update(int x, int w) {
    while (x <= n) {
        tree[x] += w;
        x += lowbit(x);
    }
}

i64 query(int x) {
    i64 sum = 0;
    while (x) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }
    for (int i = 1; i <= n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        update(l, w);
    }
    for (int i = 1; i <= n; i++) {
        }
    return 0;
}
