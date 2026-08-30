#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, c;
	cin >> n >> k >> c;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort((a).begin(), (a).end());
	a.insert(a.begin(), 0);
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	int j = 0;
	for (int x = 1; x <= c; x++) {
		while (j < n - k && a[j + 1] <= x)j++;
		cout << a[j + k] - a[j] << "\n";
	}
}
