/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-19 00:20:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-19 01:16:20
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}
const int maxn = (int)2e5 + 5;

struct Segment {
    int l, r, id;
} a[maxn << 1];
int nxt[maxn << 1][25];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        int l = read(), r = read();
        if (l > r)
            r += m;
        a[i] = {l, r, i};
    }

    std :: sort(a + 1, a + 1 + n, [](Segment a, Segment b) {
        return a.l < b.l;
    });

    for (int i = 1; i <= n; ++i) {
        auto [l, r, id] = a[i];
        a[i + n] = {l + m, r + m, i + n};
    }

    int N = n << 1;
    for (int i = 1, j = 1; i <= N; ++i) {
        while (j <= N && a[j].l <= a[i].r)
            ++j;
        nxt[a[i].id][0] = a[j - 1].id;
    }

    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= N; ++i)
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

    std :: sort(a + 1, a + 1 + N, [](Segment a, Segment b) {
        return a.id < b.id;
    });

    for (int i = 1; i <= n; ++i) {
        int ans = 2, p = i;
        for (int j = 19; ~j; --j)
            if (a[nxt[p][j]].r < a[i].l + m)
                ans += (1 << j),
                p = nxt[p][j];
        printf("%d ", ans);
    }

    puts("");
    return 0;
}