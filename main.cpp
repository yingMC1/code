#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 1e5 + 5;

int t;

struct I {
    int x, id;
} b[N];

bool cmp(I x, I y) {
    if(x.x == y.x)
        return x.id < y.id;
    else
        return x.x < y.x;
}
signed main() {
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n, x;
        cin >> n >> x;
        int a[N * 2];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i].x  = ceil(a[i] * 1.0 / x * 1.0);
            b[i].id = i;
        }
        sort(b + 1, b + 1 + n, cmp);
        cout << "Case #" << i << ": ";
        for(int i = 1; i <= n; i++)
            .cout << b[i].id << ' ';
        cout << endl;
    }
    return 0;
}
