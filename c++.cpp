#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;

int n, c, y, ans, cnt, tot, a[N];
string s;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> c >> y >> s;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] == 'H'){
            a[++tot] = cnt;
            cnt = 0;
        }
        else cnt++;
    }
    if(tot == 0)ans = 1;
    for(int i = 1; i <= tot; i++){
        int l = (y + a[i]) * 2 + 1;
        if(l > c) l = c;
        int r = y * 2 - a[i];
        if(r < 0) r = 0;
        if(l - r + 1 > 0) ans += l - r + 1;
    }
    cout << ans << endl;
    return 0;
}