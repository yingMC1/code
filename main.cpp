#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;

int T, n, a, b, cha[N];
i64 sum;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            cha[i] = a - b;
            sum += a;
        }
        sort(cha + 1, cha + n + 1);
        for (int i = n; i >= n / 2; i--) {
            sum -= cha[i];
        }
        for (int i = 1; i <= n; i++) {
            cout << cha[i] << ' ';
        }
        cout << endl;
        cout << sum << endl;
    }
    return 0;
}