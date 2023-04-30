/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-27 12:43:14 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-27 12:59:52
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
const int maxm = maxn * 3;

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

struct node {
    int x, y, z, id;
} a[maxn];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read(), z = read();
        a[i] = (node){x, y, z, i};
    }

    std :: sort(a + 1, a + 1 + n, [](node x, node y) {
        return x.x < y.x;
    });
    for (int i = 1; i < n; ++i)
        e[i] = (edge){a[i].id, a[i + 1].id, a[i + 1].x - a[i].x};
    
    std :: sort(a + 1, a + 1 + n, [](node x, node y) {
        return x.y < y.y;
    });
    for (int i = 1; i < n; ++i)
        e[n - 1 + i] = (edge){a[i].id, a[i + 1].id, a[i + 1].y - a[i].y};
    
    std :: sort(a + 1, a + 1 + n, [](node x, node y) {
        return x.z < y.z;
    });
    for (int i = 1; i < n; ++i)
        e[2 * n - 2 + i] = (edge){a[i].id, a[i + 1].id, a[i + 1].z - a[i].z};
    
    std :: iota(fa + 1, fa + 1 + n, 1);
    
    std :: sort(e + 1, e + 1 + 3 * n - 3, [](edge a, edge b) {
        return a.w < b.w;
    });

    int ans = 0;
    for (int i = 1; i < 3 * n - 2; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (unite(u, v))
            ans += w;
    }

    printf("%lld\n", ans);
    return 0;
}