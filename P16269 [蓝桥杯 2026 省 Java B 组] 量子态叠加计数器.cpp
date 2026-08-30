#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, t, f, a[N], ans;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> t >> f;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            cin >> a[j];
            a[j] += a[j - 1];
            for(int k = 1; k <= j; k++)if(a[j] - a[k - 1] == f)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}