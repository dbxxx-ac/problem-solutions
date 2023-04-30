/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-22 19:27:42 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-22 20:38:33
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

const int maxn = (int)5e5 + 5;

namespace org {
    std :: vector <int> G[maxn];
}

namespace cst {
    std :: vector <int> G[maxn << 1];
}

int dfn[maxn], low[maxn], times = 0;
int n, p;

inline void dda_edge(int u, int v) {
    cst :: G[u].push_back(v);
    cst :: G[v].push_back(u);
}

std :: stack <int> s;

void tarjan(int u) {
    if (org :: G[u].size() == 0) {
        ++p;
        return dda_edge(u, n + p);
    }

    dfn[u] = low[u] = ++times;
    s.push(u);
    
    for (int v : org :: G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            gmi(low[u], low[v]);
            if (low[v] == dfn[u]) {
                ++p;
                dda_edge(u, n + p);
                for (; ;) {
                    int x = s.top();
                    dda_edge(x, n + p);
                    s.pop();
                    if (x == v)
                        break;
                }
            }
        } else
            gmi(low[u], dfn[v]);
    } 
}

const int mlgn = 25;
const int lg = 20;

int far[maxn << 1][mlgn], dep[maxn << 1];

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    far[u][0] = fa;
    
    for (int i = 1; i <= lg; ++i)
        far[u][i] = far[far[u][i - 1]][i - 1];
    
    for (int v : cst :: G[u])
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

int main() {
    n = read();
    int m = read();
    while (m--) {
        int u = read(), v = read();
        if (u == v)
            continue;
        org :: G[u].push_back(v);
        org :: G[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u);
    
    dfs(1, 0);
    int q = read();
    while (q--) {
        int u = read(), v = read();
        int p = lca(u, v);
        printf("%d\n", (dep[u] + dep[v] - 2 * dep[p]) / 2 + 1);
    }

    return 0;
}