#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64   = long long;
const int N = 1e5 + 5;

int  n, m, ans = 1, s, a, cnt[N];
char name[N][75];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> cnt[i] >> name[i];
    for(int i = 1; i <= m; i++) {
        cin >> a >> s;
        ans = (ans + (a ^ cnt[ans] ? s : n - s)) % n, ans = (!ans ? n : ans);
    }
    cout << name[ans] << endl;
    return 0;
}
