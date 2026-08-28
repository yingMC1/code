#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, m;

double a[N];
struct node {
    double mx;
    int len;
}
t[N << 2];

int pushup(double cnt, int x, int l, int r){
    if (t[x].mx <= cnt) return 0;
    if (a[l] > cnt) return t[x].len;
    if (l == r) return a[l] > cnt;
    int mid = (l + r) >> 1;
    if (t[x * 2].mx <= cnt) return pushup(cnt, x * 2 + 1, mid + 1, r);
    else return pushup(cnt, x * 2, l, mid) + t[x].len - t[x * 2].len;
}

void update(int x, int l, int r, int q, int w){
    if(l == r && l == q){
        t[x].mx = (double) w / q;
        t[x].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (q <= mid) update(x * 2, l, mid, q, w);
    else if(q > mid) update(x * 2 + 1, mid + 1, r, q, w);
    t[x].mx = max(t[x * 2].mx, t[x * 2 + 1].mx);
    t[x].len = t[x * 2].len + pushup(t[x * 2].mx, x * 2 + 1, mid + 1, r);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        a[x] = (double) y / x;
        update(1, 1, n, x, y);
        cout << t[1].len << endl;
    }
    return 0;
}