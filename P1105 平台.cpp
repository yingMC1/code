#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, h[N], l[N], r[N];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> h[i] >> l[i] >> r[i];
    for (int i = 1; i <= n; i++){
        int ans1 = 0, ans2 = 0;
        for(int j = 1; j <= n; j++)if(h[i] > h[j] && l[i] > l[j] && l[i] < r[j] && h[ans1] < h[j])ans1 = j;
        for(int j = 1; j <= n; j++)if(h[i] > h[j] && r[i] > l[j] && r[i] < r[j] && h[ans2] < h[j])ans2 = j;
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
