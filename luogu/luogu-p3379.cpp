/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-19 10:47:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-19 11:13:19
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

const int maxn = (int)5e5 + 5;
const int mlgn = 20;
std :: vector <int> G[maxn];
int mi[mlgn][maxn], dfn[maxn], dep[maxn], times = 0;
int lg[maxn];

inline int depmin(int u, int v) {
    return dep[u] < dep[v] ? u : v;
}

void dfs(int u, int fa) {
    dfn[u] = ++times;
    dep[u] = dep[fa] + 1;
    mi[0][dfn[u]] = fa;
    for (int v : G[u]) {
        if (v != fa)
            dfs(v, u);
    }
}

inline int lca(int u, int v) {
    if (u == v)
        return u;
    u = dfn[u];
    v = dfn[v];
    if (u > v)
        std :: swap(u, v);
    int s = lg[v - u++];
    return depmin(mi[s][u], mi[s][v - (1 << s) + 1]);
}

int main() {
    int n = read(), m = read(), R = read();
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(R, 0);
    for (int j = 1; j <= lg[n]; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            mi[j][i] = depmin(mi[j - 1][i], mi[j - 1][i + (1 << (j - 1))]);
    while (m--) {
        int u = read(), v = read();
        printf("%d\n", lca(u, v));
    }
    return 0;
}