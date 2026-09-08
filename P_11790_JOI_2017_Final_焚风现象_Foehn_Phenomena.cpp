#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using i64 = long long;

struct Fenwick {
    int n;
    vector<i64> tree;

    explicit Fenwick(int n) : n(n), tree(n + 1) {}

    void add(int index, i64 value) {
        for (; index <= n; index += index & -index)
            tree[index] += value;
    }

    void range_add(int left, int right, i64 value) {
        add(left, value);
        if (right + 1 <= n)
            add(right + 1, -value);
    }

    i64 point_query(int index) const {
        i64 result = 0;
        for (; index > 0; index -= index & -index)
            result += tree[index];
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    i64 s, t;
    cin >> n >> q >> s >> t;

    vector<i64> initial(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> initial[i];

    Fenwick changes(n);
    auto height = [&](int index) {
        return initial[index] + (index == 0 ? 0 : changes.point_query(index));
    };
    auto edge_temperature = [&](int edge) {
        i64 difference = height(edge + 1) - height(edge);
        return difference > 0 ? -difference * s : -difference * t;
    };

    i64 temperature = 0;
    for (int edge = 0; edge < n; ++edge)
        temperature += edge_temperature(edge);

    while (q--) {
        int left, right;
        i64 change;
        cin >> left >> right >> change;

        temperature -= edge_temperature(left - 1);
        if (right < n)
            temperature -= edge_temperature(right);

        changes.range_add(left, right, change);

        temperature += edge_temperature(left - 1);
        if (right < n)
            temperature += edge_temperature(right);

        cout << temperature << endl;
    }

    return 0;
}
