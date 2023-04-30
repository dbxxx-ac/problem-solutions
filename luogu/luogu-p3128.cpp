/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-19 11:19:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-19 11:39:42
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

const int maxn = 50005;
const int mlgn = 18;
std :: vector <int> G[maxn];
int mi[mlgn][maxn], dfn[maxn], dep[maxn], times;
int lg[maxn], fa[maxn], ans[maxn];

inline int depmin(int u, int v) {
    return dep[u] < dep[v] ? u : v;
}

void dfs(int u, int ls) {
    dfn[u] = ++times;
    fa[u] = ls;
    dep[u] = dep[ls] + 1;
    mi[0][dfn[u]] = ls;
    for (int v : G[u])
        if (v != ls)
            dfs(v, u);
}

inline void getmi(int n) {
    for (int j = 1; j <= lg[n]; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            mi[j][i] = depmin(mi[j - 1][i], mi[j - 1][i + (1 << (j - 1))]);
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

void dfs2(int u) {
    for (int v : G[u]) {
        if (v == fa[u])
            continue;
        dfs2(v);
        ans[u] += ans[v];
    }
}

int main() {
    int n = read(), k = read();
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    getmi(n);
    
    while (k--) {
        int u = read(), v = read(), p = lca(u, v);
        ++ans[u];
        ++ans[v];
        --ans[p];
        --ans[fa[p]];
    }

    dfs2(1);
    printf("%d\n", *std :: max_element(ans + 1, ans + 1 + n));
    return 0;
}