#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int N, M;
i64 K, X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K >> X >> Y;
    vector<i64> A(N), B(M);
    for (auto& x : A)
        cin >> x;
    for (auto& x : B)
        cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<i64> prefB(M + 1, 0), prefK(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        prefB[i + 1] = prefB[i] + B[i];
        prefK[i + 1] = prefK[i] + (B[i] + K - 1) / K;
    }

    auto take = [&](i64 x) {
        i64 sum = 0;
        int cnt = 0;
        for (i64 x : A) {
            if (sum + x <= x) {
                sum += x;
                ++cnt;
            } else {
                break;
            }
        }
        return cnt;
    };

    i64 ans = take(X + Y * K);

    for (int k = 1; k <= M; ++k) {
        if (prefK[k] > Y) break;
        i64 x = X + Y * K - prefB[k];
        if (x < 0) continue;
        ans = max(ans, 1LL * k + take(x));
    }

    cout << ans << '\n';
    return 0;
}