/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-02 10:17:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 01:00:55
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
const int maxm = (int)1e5 + 25;

struct edge {
    int u, v, w;
}e[maxm];

std :: vector <std :: pair <int, int> > G[maxn], T[maxn]; // 原图 G 生成树 T

int fa[maxn];

inline int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline bool uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

std :: vector <int> p; // 特殊点的点集

int dis[52][maxn];

std :: priority_queue <std :: pair <int, int> > q;

inline bool getmin(int &a, int b) {
    return b < a ? a = b, true : false;
}

inline void dijkstra(int k, int n) {
    int s = p[k];
    std :: memset(dis[k], 0x3f, sizeof(dis[k])) ;
    dis[k][s] = 0;
    q.emplace(0, s);

    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[k][u] != 0)
            continue;
        
        for (auto e : G[u]) {
            int v = e.first, w = e.second;
            if (getmin(dis[k][v], dis[k][u] + w))
                q.emplace(-dis[k][v], v);
        }
    }
}

const int mlgn = 25, lgn = 20;
int fat[maxn][mlgn];
int d[maxn], pr[maxn];

void dfs(int u, int fa) {
    fat[u][0] = fa;
    for (int i = 1; i <= lgn; ++i)
        fat[u][i] = fat[fat[u][i - 1]][i - 1];
    
    for (auto e : T[u]) {
        int v = e.first, w = e.second;
        if (v == fa)
            continue;
        pr[v] = pr[u] + w;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

inline int lca(int u, int v) {
    if (d[u] < d[v])
        u ^= v ^= u ^= v;
    for (int i = lgn; ~i; --i)
        if (d[fat[u][i]] >= d[v])
            u = fat[u][i];
    
    if (u == v)
        return u;

    for (int i = lgn; ~i; --i) {
        if (fat[u][i] != fat[v][i]) {
            u = fat[u][i];
            v = fat[v][i];
        }
    }

    return fat[u][0];
}

signed main() {
    int n = read(), m = read();
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        e[i] = (edge){u, v, w};
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    std :: sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.w < b.w;
    });

    std :: iota(fa + 1, fa + 1 + n, 1LL);
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (uni(u, v)) {
            T[u].emplace_back(v, w);
            T[v].emplace_back(u, w);
        } else {
            p.push_back(u);
            p.push_back(v);
        }
    }

    dfs(1, 0);
    const int pn = p.size();
    for (int i = 0; i < pn; ++i)
        dijkstra(i, n); // 对所有特殊点在 G 上跑 dijkstra
    
    int q = read();
    while (q--) {
        int u = read(), v = read();
        int ans = pr[u] + pr[v] - (pr[lca(u, v)] << 1); // 第一种最短路
        for (int i = 0; i < pn; ++i)
            getmin(ans, dis[i][u] + dis[i][v]); // 包含第二种最短路（可能更优）
        printf("%lld\n", ans);
    }

    return 0;
}