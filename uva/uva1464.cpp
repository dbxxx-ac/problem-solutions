/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-23 07:47:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-23 09:10:53
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

const int maxn = 10005;
const int maxm = 100005;

namespace org {
    std :: vector <int> G[maxn];
}

namespace cst {
    std :: vector <int> G[maxn << 1];
}

int n, p;

int low[maxn], dfn[maxn], times = 0;
std :: stack <int> s;

inline void dda_edge(int u, int v) {
    cst :: G[u].push_back(v);
    cst :: G[v].push_back(u);
}

void tarjan(int u) {
    if (org :: G[u].empty()) {
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
                    s.pop();
                    dda_edge(x, n + p);
                    if (x == v)
                        break;
                }
            }
        } else
            gmi(low[u], dfn[v]);
    }
}

int us[maxm], vs[maxm];

const int mlgn = 17;
const int lg = 15;

int far[maxn << 1][mlgn], dep[maxn << 1];

void dfs(int u, int fa) {
    far[u][0] = fa;
    dep[u] = dep[fa] + 1;
    
    for (int i = 1; i <= lg; ++i)
        far[u][i] = far[far[u][i - 1]][i - 1];
    
    for (int v : cst :: G[u])
        if (v != fa)
            dfs(v, u);
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

inline void init(int n) {
    for (int u = 1; u <= n; ++u)
        dfn[u] = 0;
    for (int u = 1; u <= n; ++u)
        org :: G[u].clear();
    for (int u = 1; u <= n * 2; ++u)
        cst :: G[u].clear();
    p = 0;
}

inline int cal(int u, int v) {
    int p = lca(u, v);
    return (dep[u] + dep[v] - dep[p] * 2) / 2 - 1;
}

signed main() {
    n = read();
    int m = read();
    for (; n || m; n = read(), m = read()) {
        init(n);
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            org :: G[u].push_back(v);
            org :: G[v].push_back(u);
            us[i] = u;
            vs[i] = v;
        }

        for (int u = 1; u <= n; ++u) {
            if (!dfn[u]) {
                tarjan(u);
                dfs(u, 0);
            }
        }
        
        int q = read();
        while (q--) {
            int a = read(), b = read();
            printf("%d\n", std :: max({
                cal(us[a], us[b]),
                cal(us[a], vs[b]),
                cal(vs[a], us[b]),
                cal(vs[a], vs[b])
            }));
        }
    }

    return 0;
}