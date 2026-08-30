#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e6 + 5;

int a[] = {5160, 9191, 6410, 4657, 7492, 1531, 8854, 1253, 4520, 9231, 1266, 4801, 3484, 4323, 5070, 1789, 2744, 5959, 9426, 4433, 4404, 5291, 2470, 8533, 7608, 2935, 8922, 5273, 8364, 8819, 7374, 8077, 5336, 8495, 5602, 6553, 3548, 5267, 9150, 3309};
long long sum, mx, ans;
bool dp[N];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for(int i : a)sum += i;
    sum /= 2;
    dp[0] = 1;
    for (int k : a)
        for (int i = sum; i >= k - 1; i--)
            if (dp[i - k])dp[i] = 1;
    for (int i = sum; i >= 0; i--){
        if (dp[i]){
            mx = i;
            break;
        }
    }
    ans = mx * (sum * 2 - mx);
    cout << ans << endl;
    return 0;
}