#include <bits/stdc++.h>
using namespace std;

using db = double;

const int MOD1 = 39989;      // x 坐标取模范围
const int MOD2 = 1000000000; // y 坐标取模范围
const int MAXN = 40000 + 5;  // 离散 x 范围：1 ~ 39989
const db EPS = 1e-10;        // 浮点比较精度
const db NEG_INF = -1e18;    // 负无穷，表示空线段

// ==================== 线段结构体 ====================
// 表示一条线段所在的直线 y = k*x + b，以及它的编号 id
// 注意：这里的“线段”在插入时已经拆成若干完全覆盖节点，
// 每个节点内部按“直线”方式比较，所以结构体本身只存 k, b, id
struct Line {
    db k, b;    // 斜率、截距
    int id;     // 线段编号，用于输出
    bool empty; // 是否为空（该节点还没有任何线段）

    Line(db _k = 0, db _b = NEG_INF, int _id = 0, bool _empty = true)
        : k(_k), b(_b), id(_id), empty(_empty) {}

    // 计算 x 处的函数值；空线返回负无穷
    db get(int x) const {
        if (empty) return NEG_INF;
        return k * x + b;
    }
};

// ==================== 李超线段树 ====================
struct LiChao {
    int n;           // 值域大小（x 的下标范围 1..n）
    vector<Line> tr; // 线段树节点，每个节点存一条“优势线段”

    LiChao(int _n) : n(_n) {
        tr.assign(4 * n + 5, Line()); // 全部初始化为空线
    }

    // ---------- 核心：在节点 [l,r] 内插入一条“直线” ----------
    // 调用前提：这条直线在 [l,r] 整个区间内都有效（由 insert 保证）
    // 逻辑：
    //   1. 比较 u 和当前节点线段在中点 mid 的值，让中点更优者留下
    //   2. 被换出的线只可能在左半或右半某一侧反超，递归到那一侧
    //   3. 如果两侧都不反超，直接丢弃
    void add_line(int p, int l, int r, Line u) {
        if (u.empty) return; // 空线不插入

        int mid = (l + r) >> 1;

        // 当前节点为空，或 u 在中点更优，则交换，保证节点存的是中点更优的线
        // 注意等值情况：如果值相同，保留编号更小的那条
        if (tr[p].empty) {
            tr[p] = u;
            return;
        }

        bool u_better_mid = u.get(mid) > tr[p].get(mid) + EPS;
        bool equal_mid = fabs(u.get(mid) - tr[p].get(mid)) <= EPS;

        if (u_better_mid || (equal_mid && u.id < tr[p].id)) {
            swap(u, tr[p]); // 交换后，tr[p] 是中点更优的线，u 是待下传的线
        }

        // 叶子节点，无法继续下传
        if (l == r) return;

        // 判断被换出的线 u 是否在左端点更优
        // 如果在左端点更优，说明交点偏左，u 只可能在左半区间反超
        bool u_better_l = u.get(l) > tr[p].get(l) + EPS;
        // 判断被换出的线 u 是否在右端点更优
        bool u_better_r = u.get(r) > tr[p].get(r) + EPS;

        if (u_better_l) {
            add_line(p << 1, l, mid, u);
        } else if (u_better_r) {
            add_line(p << 1 | 1, mid + 1, r, u);
        }
        // 否则 u 在两端都不优，整个区间都不优，直接丢弃
    }

    // ---------- 插入线段：把定义域 [ql,qr] 拆成若干完全覆盖节点 ----------
    // 这是与“插入整条直线”的唯一区别
    void insert(int p, int l, int r, int ql, int qr, Line u) {
        if (qr < l || r < ql) return; // 无交集

        if (ql <= l && r <= qr) {
            // 当前节点被完全覆盖，直接在这个节点执行直线插入
            add_line(p, l, r, u);
            return;
        }

        int mid = (l + r) >> 1;
        insert(p << 1, l, mid, ql, qr, u);
        insert(p << 1 | 1, mid + 1, r, ql, qr, u);
    }

    // ---------- 查询：单点 x 处的最优线段 ----------
    // 由于标记永久化，需要取根到叶子路径上所有节点线段在 x 处的最大值
    Line query(int p, int l, int r, int x) {
        if (l == r) return tr[p];

        int mid = (l + r) >> 1;
        Line res = tr[p]; // 当前节点的线段

        if (x <= mid) {
            Line sub = query(p << 1, l, mid, x);
            // 比较子节点返回的最优线段与当前节点线段
            if (sub.get(x) > res.get(x) + EPS ||
                (fabs(sub.get(x) - res.get(x)) <= EPS && sub.id < res.id)) {
                res = sub;
            }
        } else {
            Line sub = query(p << 1 | 1, mid + 1, r, x);
            if (sub.get(x) > res.get(x) + EPS ||
                (fabs(sub.get(x) - res.get(x)) <= EPS && sub.id < res.id)) {
                res = sub;
            }
        }
        return res;
    }

    // ---------- 对外接口：插入线段，x 范围 [L,R] ----------
    void insert_segment(int L, int R, Line u) {
        if (L > R) swap(L, R);
        // 注意：如果线段范围超出 [1,n]，需要裁剪，防止越界
        L = max(L, 1);
        R = min(R, n);
        if (L > R) return;
        insert(1, 1, n, L, R, u);
    }

    // ---------- 对外接口：查询 x 处最优线段 ----------
    Line query_point(int x) { return query(1, 1, n, x); }
};

// ==================== 主程序 ====================
int main() {
    int n;
    scanf("%d", &n);

    LiChao lichao(MAXN); // x 范围 [1, 39989]，开 MAXN 足够

    int lastans = 0; // 上一次查询的答案，用于强制在线解密
    int idx = 0;     // 当前线段编号计数器

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 0) {
            // ---------- 查询操作 ----------
            int k;
            scanf("%d", &k);
            // 解密 x： (k + lastans - 1) mod 39989 + 1
            int x = (k + lastans - 1) % MOD1 + 1;

            Line ans = lichao.query_point(x);
            printf("%d\n", ans.id);

            lastans = ans.id; // 更新 lastans 为本次答案编号
        } else {
            // ---------- 插入操作 ----------
            int x0, y0, x1, y1;
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);

            // 解密四个坐标
            x0 = (x0 + lastans - 1) % MOD1 + 1;
            y0 = (y0 + lastans - 1) % MOD2 + 1;
            x1 = (x1 + lastans - 1) % MOD1 + 1;
            y1 = (y1 + lastans - 1) % MOD2 + 1;

            idx++; // 线段编号从 1 开始递增

            if (x0 == x1) {
                // 垂直线段：不能计算斜率
                // 当作定义域为 [x0, x0] 的“函数”，值为 max(y0, y1)
                // 用 k=0, b=max(y0,y1) 表示，只在 x0 处有效
                lichao.insert_segment(x0, x0, Line(0, max(y0, y1), idx, false));
            } else {
                // 一般线段：先保证 x0 < x1，方便计算
                if (x0 > x1) {
                    swap(x0, x1);
                    swap(y0, y1);
                }
                // 计算斜率 k = (y1 - y0) / (x1 - x0)
                db k = (db)(y1 - y0) / (x1 - x0);
                // 截距 b = y0 - k * x0
                db b = y0 - k * x0;

                lichao.insert_segment(x0, x1, Line(k, b, idx, false));
            }
        }
    }

    return 0;
}