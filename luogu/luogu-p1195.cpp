/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-23 20:55:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-23 21:00:49
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

const int maxn = (int)1e3 + 5;
const int maxm = (int)1e4 + 5;
struct edge {
    int u, v, w;
} e[maxm];
int fa[maxn];

inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

int main() {
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        e[i] = (edge){u, v, w};
    }

    std :: sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.w < b.w;
    });

    std :: iota(fa + 1, fa + 1 + n, 1);

    int blo = n, ans = 0;

    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (unite(u, v)) {
            ans += w;
            --blo;
            if (blo == k) {
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    puts("No Answer");
    return 0;
}