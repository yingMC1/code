#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, m, a[N], sum, ans = 1;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        if(sum > m)sum = a[i], ans++;
    }
    cout << ans << endl;
    return 0;
}
