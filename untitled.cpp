#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;

int T, n;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int ans = n;
        for (int f = 0; f < 2; f++)
        {
            int dp[2] = {n + 1, n + 1};
            dp[f] = 0;
            for (int j = 1; j < n; j++)
            {
                int f[2] = {n + 1, n + 1};
                for (int k = 0; k < 2; k++)
                {
                    for (int cnt = 0; cnt < 2; cnt++)
                    {
                        char r = k ? s[j - 1][0] : s[j - 1][1];
                        char l = cnt ? s[j][1] : s[j][0];
                        f[cnt] = min(f[cnt], dp[k] + (r != l));
                    }
                }
                dp[0] = f[0];
                dp[1] = f[1];
            }
            for (int t = 0; t < 2; t++)
            {
                char r = t ? s[n - 1][0] : s[n - 1][1];
                char l = f ? s[0][1] : s[0][0];
                ans = min(ans, dp[t] + (r != l));
            }
        }
        cout << ans << endl;
    }
    return 0;
}