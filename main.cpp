#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;

int n, a[N];

int main() {
    cin >> n;
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        if (i >= 3) cout << *prev(s.end(), 3) << endl;
    }
    return 0;
}