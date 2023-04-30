/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-24 08:22:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-24 08:39:56
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = (int)1e5 + 5;
bool blk[maxn];
int fa[maxn];

struct edge {
    int u, v, w;
} e[maxn];

inline int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

signed main() {
    int n = read(), k = read();
    while (k--)
        blk[read() + 1] = true;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int u = read() + 1, v = read() + 1, w = read();
        e[i] = (edge){u, v, w};
        ans += w;
    }

    std :: sort(e + 1, e + n, [](edge a, edge b) {
        return a.w > b.w;
    });

    std :: iota(fa + 1, fa + 1 + n, 1);
    for (int i = 1; i < n; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        u = find(u);
        v = find(v);
        if (blk[u] && blk[v])
            continue;
        fa[v] = u;
        blk[u] = blk[v] = (blk[u] || blk[v]);
        ans -= w;
    }
    printf("%lld\n", ans);
    return 0;
}