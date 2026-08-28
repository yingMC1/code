#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int l, n, a[N] = {1}, ans1, ans2;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> l >> n;
    for (int i = 1; i <= n; i++){
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 0){
            for (int i = l; i <= r; i++){
                if (a[i] == 0 || a[i] == 2){
                    if(a[i] == 2)ans2++;
                    a[i] = 0;
                }
            }
        }
        else for (int i = l; i <= r; i++)if (a[i] == 0)a[i] = 2;
    }
    for (int i = 1; i <= n; i++)if (a[i])ans1++;
    cout << ans1 << endl << ans2 << endl;
    return 0;
}
