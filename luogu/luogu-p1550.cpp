/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-24 08:46:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-24 08:53:29
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

const int maxn = 305;
int a[maxn][maxn];
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

struct edge {
    int u, v, w;
};
std :: vector <edge> es;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        es.push_back({i, n + 1, read()});
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int w = read();
            if (u >= v)
                continue;
            es.push_back({u, v, w});
        }
    }

    std :: sort(es.begin(), es.end(), [](edge a, edge b) {
        return a.w < b.w;
    });

    std :: iota(fa + 1, fa + 2 + n, 1);
    int ans = 0;
    for (edge e : es) {
        int u = e.u, v = e.v, w = e.w;
        if (unite(u, v))
            ans += w;
    }
    printf("%d\n", ans);
    return 0;
}