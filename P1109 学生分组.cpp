#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 55;

int n, a[N], l, r, sum, minn, maxx;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], sum += a[i];
    cin >> l >> r;
    if (sum < l * n || sum > n * r){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (a[i] < l)minn += l - a[i];
        if (a[i] > r)maxx += (a[i] - r);
    }
    cout << max(maxx, minn) << endl;
    return 0;
}