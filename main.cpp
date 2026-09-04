#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;

i64 n, x, tot, cnt, ans, sum;
map<i64, int> mp;
char c;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> c;
        i64 cnt1 = c == 'L' ? cnt - x : cnt + x;
        i64 l = min(cnt, cnt1);
        i64 r = max(cnt, cnt1);
        if (l != r) {
            mp[l]++;
            mp[r]--;
        }
        cnt = cnt1;
    }
    auto b = mp.begin();
    while (b != mp.end()) {
        sum += b->second;
        auto net = std::next(b);
        if (net != mp.end()) {
            i64 l = net->first - b->first;
            if (sum > tot) {
                tot = sum;
                ans = l;
            } else if (sum == tot)
                ans += l;
        }
        b = net;
    }
    cout << tot << endl << ans << endl;
    return 0;
}