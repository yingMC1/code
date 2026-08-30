#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, a[N];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int k = 1; k <= n; k++){
        int sum = 0;
        for (int j = k; j <= n; j++){
            sum += a[j];
            if (sum % 10 == 0){
                cout << j - k + 1;
                break;
            }
        }
        if (sum % 10 != 0) cout <<-1;
        cout << ' ';
    }
    return 0;
}