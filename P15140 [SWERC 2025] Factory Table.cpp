#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 105;

int t, a[105];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n, s = 0, s2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] <= a[i - 1]){
                s = a[i - 1];
                s2 = a[i];
            }
        }
        if (s != 0)cout << s / (s2 - 1) << endl;
        else cout << max(a[n] - a[n - 1], a[n] / (a[n] - a[n - 1])) << endl;

    }
    return 0;
}
