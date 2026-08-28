#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 500005;

int maxx[10], cnt[10][N];
int n, t, p, ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p >> t;
        maxx[p] = max(maxx[p], t);
        cnt[p][t]++;
    }
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j <= maxx[i];){
            if (cnt[i][j]){
                ans++;
                j += 60;
            }
            else j++;
        }
    }
    cout << ans;
    return 0;
}