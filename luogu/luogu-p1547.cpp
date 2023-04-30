/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-16 21:09:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-16 23:32:51
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

const int maxn = 2005;

int fa[maxn];

inline int get(int x) {
    while (x != fa[x])  
        x = fa[x] = fa[fa[x]];
    return x;
}

inline bool uni(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

const int maxm = (int)1e4 + 5;

struct edge {
    int u, v, w;
} e[maxm];

int main() {
    int n = read(), m = read();
    std :: iota(fa + 1, fa + 1 + n, 1);
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        e[i] = (edge){u, v, w};
    }

    std :: sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.w < b.w;
    });

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (uni(u, v))
            ans = w;
    }

    printf("%d\n", ans);
    return 0;
}