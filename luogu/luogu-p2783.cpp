/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-22 20:46:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-22 21:15:05
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = (int)1e4 + 5;

namespace org {
    std :: vector <int> G[maxn];
}

namespace tr {
    std :: vector <int> G[maxn];
}

int low[maxn], dfn[maxn], eno[maxn], times = 0, ent = 0;
std :: stack <int> s;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++times;
    s.push(u);

    for (int v : org :: G[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            gmi(low[u], low[v]);
        } else if (v != fa)
            gmi(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++ent;
        for (; ;) {
            int x = s.top();
            s.pop();
            eno[x] = ent;
            if (x == u)
                break;
        }
    }
}

const int maxm = (int)5e4 + 5;
int us[maxm], vs[maxm];

const int mlgn = 17;
const int lg = 15;

int far[maxn][mlgn], dep[maxn];

void dfs(int u, int fa) {
    far[u][0] = fa;
    dep[u] = dep[fa] + 1;
    
    for (int i = 1; i <= lg; ++i)
        far[u][i] = far[far[u][i - 1]][i - 1];
    
    for (int v : tr :: G[u])
        if (v != fa)
            dfs(v, u);

    return ;
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v])
        std :: swap(u, v);
    
    for (int i = lg; ~i; --i)
        if (dep[far[u][i]] >= dep[v])
            u = far[u][i];
    
    if (u == v)
        return u;
    
    for (int i = lg; ~i; --i) {
        if (far[u][i] != far[v][i]) {
            u = far[u][i];
            v = far[v][i];
        }
    }

    return far[u][0];
}

void out(int x) {
    if (!x)
        return ;
    out(x >> 1);
    putchar('0' + (x & 1));
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        org :: G[u].push_back(v);
        org :: G[v].push_back(u);
        us[i] = u;
        vs[i] = v;
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u, 0);
    
    for (int i = 1; i <= m; ++i) {
        int u = us[i], v = vs[i];
        u = eno[u];
        v = eno[v];
        if (u == v)
            continue;
        tr :: G[u].push_back(v);
        tr :: G[v].push_back(u);
    }
    
    dfs(1, 0);
    int q = read();
    while (q--) {
        int u = eno[read()], v = eno[read()];
        int p = lca(u, v);
        out(dep[u] + dep[v] - 2 * dep[p] + 1);
        puts("");
    }

    return 0;
}