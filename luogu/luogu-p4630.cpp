/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-23 00:39:18 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-23 01:50:30
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = 100005;

namespace org {
    std :: vector <int> G[maxn];
}

namespace cst {
    std :: vector <int> G[maxn << 1];
}

int n, p;

inline void dda_edge(int u, int v) {
    cst :: G[u].push_back(v);
    cst :: G[v].push_back(u);
}

int dfn[maxn], low[maxn], times = 0;
std :: stack <int> s;

int tot;

void tarjan(int u) {
    ++tot;
    
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

int siz[maxn << 1], ans = 0;

void dfs(int u, int fa) {
    int con = ((u <= n) ? -1 : cst :: G[u].size());
    int cnt = ((u <= n) ? (tot - 1) : 0);
    
    siz[u] = ((u <= n) ? 1 : 0);
    for (int v : cst :: G[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        cnt += siz[v] * (tot - siz[v]);
        siz[u] += siz[v];
    }

    cnt += (tot - siz[u]) * siz[u];
    ans += cnt * con;
}

signed main() {
    n = read(); int m = read();
    while (m--) {
        int u = read(), v = read();
        if (u == v)
            continue;
        org :: G[u].push_back(v);
        org :: G[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        if (!dfn[u]) {
            tot = 0;
            tarjan(u);
            dfs(u, 0);
        }
    }

    printf("%lld\n", ans);
    return 0;
}