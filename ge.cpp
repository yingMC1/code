#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0) ^ (unsigned long long)(new char));
    // 小数据方便对拍
    int n = rand() % 10;
    int m = rand() % 10 + 1;
    int MAXC = 6; // 坐标范围小一点，容易撞出重复点

    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        int x = rand() % (MAXC + 1);
        int y = rand() % (MAXC + 1);
        printf("%d %d\n", x, y);
    }
    for (int i = 1; i <= m; i++) {
        int a = rand() % (MAXC + 1);
        int c = rand() % (MAXC + 1);
        int b = rand() % (MAXC + 1);
        int d = rand() % (MAXC + 1);
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        printf("%d %d %d %d\n", a, b, c, d);
    }
    return 0;
}