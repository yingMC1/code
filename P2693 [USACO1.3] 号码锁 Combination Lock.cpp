#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int n, a1, b1, c1, a2, b2, c2, ans;
bool bo[105][105][105];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    for (int i = a1 - 2;i <=  a1 + 2; i++)
        for (int j = b1 - 2;j <=  b1 + 2; j++) 
            for (int k = c1 - 2;k <=  c1 + 2; k++)
                if (!bo[(i + n) % n][(j + n) % n][(k + n) % n])
                    ans++ , bo[(i + n) % n][(j + n) % n][(k + n) % n] = true;
    for (int i = a2 - 2;i <=  a2 + 2; i++)
        for (int j = b2 - 2;j <=  b2 + 2; j++)
            for (int k = c2 - 2;k <=  c2 + 2; k++)
                if (!bo[(i + n) % n][(j + n) % n][(k + n) % n])
                    ans++ , bo[(i + n) % n][(j + n) % n][(k + n) % n] = true;
    cout << ans << endl;
    return 0;
}