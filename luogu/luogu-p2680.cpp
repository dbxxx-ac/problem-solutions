/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-19 12:55:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-19 13:33:47
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = 300005;
const int maxm = 300005;
const int mlgn = 20;

int n, m;

typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int lg[maxn], fa[maxn], prew[maxn], dep[maxn], dfn[maxn], dis[maxn], mi[mlgn][maxn], times = 0;

inline int depmin(int u, int v) {
    return dep[u] < dep[v] ? u : v;
}

void dfs(int u, int ls) {
    dfn[u] = ++times;
    dep[u] = dep[ls] + 1;
    fa[u] = mi[0][dfn[u]] = ls;
    for (pii e : G[u]) {
        int v = e.first, w = e.second;
        if (v == ls)
            continue;
        dis[v] = dis[u] + w;
        prew[v] = w;
        dfs(v, u);
    }
}

inline void getmi() {
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

struct query {
    int s, t, L;
} q[maxn];

int cnt[maxn];

void dfs2(int u) {
    for (pii e : G[u]) {
        int v = e.first;
        if (v == fa[u])
            continue;
        dfs2(v);
        cnt[u] += cnt[v];
    }
}

inline bool check(int x) {
    int tot = 0;
    std :: memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= m; ++i) {
        int s = q[i].s, t = q[i].t, L = q[i].L, p = lca(s, t);
        if (L <= x) {
            tot = i - 1;
            break;
        }
        ++cnt[s];
        ++cnt[t];
        cnt[p] -= 2;
    }

    dfs2(1);

    int maxw = 0;
    for (int u = 1; u <= n; ++u) {
        if (cnt[u] == tot)
            gmx(maxw, prew[u]);
    }

    return q[1].L - maxw <= x;
}

int main() {
    n = read(); m = read();
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(1, 0);
    getmi();

    for (int i = 1; i <= m; ++i) {
        int s = q[i].s = read(), t = q[i].t = read(), p = lca(s, t);
        q[i].L = dis[s] + dis[t] - dis[p] * 2;
    }

    std :: sort(q + 1, q + 1 + m, [](query a, query b) {
        return a.L > b.L;
    });

    int ans = 0;
    if (check(0)) {
        puts("0");
        return 0;
    }
    
    for (int i = (1 << 30); i; i >>= 1)
        if (!check(ans + i))
            ans += i;
    printf("%d\n", ans + 1);
    return 0;
}