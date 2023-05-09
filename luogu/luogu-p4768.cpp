/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-04 09:53:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-04 11:30:49
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

const int N = (int)2e5 + 5;
const int M = (int)4e5 + 5;

struct edge {
    int u, v, l, a;
} e[M];

typedef std :: pair <int, int> pii;
std :: vector <pii> G[N];
std :: vector <int> T[N << 1];

int dis[N << 1], hei[N << 1], dep[N << 1];
const int lg = 20;
int far[N << 1][lg + 5];

struct DSU {
    int fa[N << 1];
    inline void init() {
        std :: iota(fa + 1, fa + (N << 1), 1LL);
    }
    inline int find(int x) {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    }
} dsu;

inline void dijkstra() {
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    std :: priority_queue <pii> q;
    q.push({0, 1});

    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u])
            continue;
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

int n, m;
inline void kruskal() {
    std :: sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.a > b.a;
    });
    int p = n;

    dsu.init();
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, a = e[i].a;
        u = dsu.find(u);
        v = dsu.find(v);
        if (u == v)
            continue;
        dsu.fa[u] = ++p;
        dsu.fa[v] = p;
        hei[p] = a;
        dis[p] = std :: min(dis[u], dis[v]);
        T[u].push_back(p);
        T[p].push_back(u);
        T[v].push_back(p);
        T[p].push_back(v);
    }

    return ;
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    far[u][0] = fa;
    for (int i = 1; i <= lg; ++i)
        far[u][i] = far[far[u][i - 1]][i - 1];
    for (int v : T[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

inline int query(int u, int a) {
    for (int i = lg; ~i; --i)
        if (dep[u] > (1 << i) && hei[far[u][i]] > a)
            u = far[u][i];
    return dis[u];
}

inline void clear() {
    for (int u = 1; u <= n; ++u)
        G[u].clear();
    for (int u = 1; u <= 2 * n - 1; ++u)
        T[u].clear();
}

signed main() {
    int T = read();
    while (T--) {
        n = read();
        m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read(), l = read(), a = read();
            e[i] = (edge){u, v, l, a};
            G[u].push_back({v, l});
            G[v].push_back({u, l});
        }
        dijkstra();
        kruskal();
        dfs(n * 2 - 1, 0);
        int Q = read(), K = read(), S = read();
        int lastans = 0;
        while (Q--) {
            int u = (read() + K * lastans - 1) % n + 1;
            int a = (read() + K * lastans) % (S + 1);
            printf("%lld\n", lastans = query(u, a));
        }
        clear();
    }
    return 0;
}