#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = unsigned long long;
const int N = 3e5 + 5;

int T, n, a[N], b[N], ans[N], q;
int sta[N], topa, stb[N], topb;
vector<pair<int, int>> t[N];

struct I {
    i64 adda, addb, s, sa, sb, upd, h, ha, hb, ans, l;
}
s[N * 4];

void push_up(int u){
    s[u].s = s[u * 2].s + s[u * 2 + 1].s;
    s[u].sa = s[u * 2].sa + s[u * 2 + 1].sa;
    s[u].sb = s[u * 2].sb + s[u * 2 + 1].sb;
    s[u].ans = s[u * 2].ans + s[u * 2 + 1].ans;
}

void spread(int u, I v){
    s[u].ans += s[u].s * v.upd + s[u].sa * v.hb + s[u].sb * v.ha + v.h * s[u].l;
    s[u].h += s[u].adda * s[u].addb * v.upd + s[u].adda * v.hb + s[u].addb * v.ha + v.h;
    s[u].ha += s[u].adda * v.upd + v.ha;
    s[u].hb += s[u].addb * v.upd + v.hb;
    s[u].s += s[u].sa * v.addb + s[u].sb * v.adda + v.addb * v.adda * s[u].l;
    s[u].sa += v.adda * s[u].l;
    s[u].sb += v.addb * s[u].l;
    s[u].upd += v.upd;
    s[u].adda += v.adda;
    s[u].addb += v.addb;
}

void push_down(int u){
    spread(u * 2, s[u]), spread(u * 2 + 1, s[u]);
    s[u].h = 0, s[u].ha = 0, s[u].hb = 0, s[u].upd = 0, s[u].adda = 0, s[u].addb = 0;
}

void build(int u, int l, int r){
    s[u].l = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
}

void update(int u, int L, int R, int l, int r, i64 x, int tp){
    if (l > r) return;
    if (l <= L && R <= r){
        if (tp == 0) spread(u, (I){x, 0, 0, 0, 0, 0, 0, 0, 0, 0, (i64)R - L + 1});
        else spread(u, (I){0, x, 0, 0, 0, 0, 0, 0, 0, 0, (i64)R - L + 1});
        return;
    }
    push_down(u);
    int mid = (L + R) >> 1;
    if (l <= mid) update(u * 2, L, mid, l, r, x, tp);
    if (mid < r) update(u * 2 + 1, mid + 1, R, l, r, x, tp);
    push_up(u);
}

i64 query(int u, int L, int R, int l, int r){
    if (l <= L && R <= r) return s[u].ans;
    int mid = (L + R) >> 1;
    push_down(u);
    i64 res = 0;
    if (l <= mid) res += query(u * 2, L, mid, l, r);
    if (mid < r) res += query(u * 2 + 1, mid + 1, R, l, r);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> T >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];
    cin >> q;
    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        t[r].push_back({l, i});
    }
    build(1, 1, n);
    topa = 1, topb = 1;
    a[0] = n + 1, b[0] = n + 1;
    for (int i = 1; i <= n; i++){
        while (a[sta[topa]] < a[i]){
            update(1, 1, n, sta[topa - 1] + 1, sta[topa],-a[sta[topa]], 0);
            topa--;
        }
        update(1, 1, n, sta[topa] + 1, i, a[i], 0);
        sta[++topa] = i;
        while (b[stb[topb]] < b[i]){
            update(1, 1, n, stb[topb - 1] + 1, stb[topb],-b[stb[topb]], 1);
            topb--;
        }
        update(1, 1, n, stb[topb] + 1, i, b[i], 1);
        stb[++topb] = i;
        spread(1, (I){0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
        for (auto j : t[i]) ans[j.second] = query(1, 1, n, j.first, i);
    }
    for (int i = 1; i <= q; i++)cout << ans[i] << endl;
    return 0;
}