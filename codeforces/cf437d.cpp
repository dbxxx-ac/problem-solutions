/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-13 23:56:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-14 00:06:16
 */
#include <bits/stdc++.h>
#define int long long
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = (int)1e5 + 5;
const int maxm = (int)1e5 + 5;

struct edge {
    int u, v, w;
}e[maxm];

int a[maxn];

inline int min(int a, int b) {
    return a < b ? a : b;
}

int fa[maxn], siz[maxn];

inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline void uni(int x, int y) {
    if (siz[x] > siz[y])
        x ^= y ^= x ^= y;
    fa[x] = y;
    siz[y] += siz[x];
}

signed main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        int w = min(a[u], a[v]);
        e[i] = (edge){u, v, w};
    }

    std :: sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.w > b.w;
    });

    std :: iota(fa + 1, fa + 1 + n, 1);
    std :: fill(siz + 1, siz + 1 + n, 1);
    
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        u = get(u);
        v = get(v);
        if (u == v)
            continue;
        ans += 2 * siz[u] * siz[v] * w;
        uni(u, v);
    }

    printf("%.6f\n", ans * 1.0 / (n * (n - 1)));
    return 0;
}