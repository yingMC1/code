#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;

int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            for(int j = 1; j <= m; j++)
                cout << (i - 1) * m + j << " ";
            cout << endl;
        } else {
            for(int j = m; j; j--)
                cout << (i - 1) * m + j << " ";
            cout << endl;
        }
    }
    return 0;
}