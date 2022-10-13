/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-11 22:33:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-12 03:10:21
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

typedef std :: pair <int, int> pii;

const int maxn = 205;
const int maxm = (int)5e4 + 5;
int fru[maxm], tov[maxm], wei[maxm], ext[maxm];

int n;

struct graph {
    graph() {
        std :: memset(ont, false, sizeof(ont));
        std :: memset(pre, 0, sizeof(pre));
    }

    int s;
    std :: vector <pii> G[maxn];
    
    inline void add_edge(int u, int v, int id) {
        G[u].emplace_back(v, id);
    }

    int d[maxn], dis[maxn], pre[maxn];
    bool ont[maxm], vis[maxn];

    inline void dijkstra(int ban) {
        std :: memset(dis, 0x3f, sizeof(dis));
        std :: memset(vis, false, sizeof(vis));
        dis[s] = 0;
        for (int i = 1; i <= n; ++i) {
            int u = n + 1;
            for (int j = 1; j <= n; ++j)
                if (!vis[j] && dis[j] < dis[u])
                    u = j;
            if (u == n + 1)
                break ;
            vis[u] = true;
            
            for (pii e : G[u]) {
                int v = e.first, id = e.second, w = wei[id];
                if (id == ban)
                    continue;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (ban)
                        continue;
                    ont[pre[v]] = false;
                    pre[v] = id;
                    ont[pre[v]] = true;
                }
            }
        }

        if (!ban)
            std :: copy(dis + 1, dis + 1 + n, d + 1);
    }

    inline int get(int x, int id) { // 删除 id 后 s 到 x 的距离
        if (!ont[id])
            return d[x];
        
        dijkstra(id);
        
        return dis[x];
    }
} G1, Gn, R1, Rn;

inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

signed main() {
    n = read();
    int m = read();
    
    G1.s = R1.s = 1;
    Gn.s = Rn.s = n;

    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read(), ex = read();
        G1.add_edge(u, v, i);
        Gn.add_edge(u, v, i);
        R1.add_edge(v, u, i);
        Rn.add_edge(v, u, i);
        fru[i] = u;
        tov[i] = v;
        wei[i] = w;
        ext[i] = ex;
    }

    G1.dijkstra(0);
    Gn.dijkstra(0);
    R1.dijkstra(0);
    Rn.dijkstra(0);
    
    int ans = G1.d[n] + Gn.d[1];
    
    for (int i = 1; i <= m; ++i) {
        int u = fru[i], v = tov[i], w = wei[i], ex = ext[i];
        gmi(ans, 
            min(G1.get(n, i), G1.get(v, i) + w + Rn.get(u, i)) + 
            min(Gn.get(1, i), Gn.get(v, i) + w + R1.get(u, i)) + ex
        );
    }

    if (ans >= G1.dis[n + 1])
        puts("-1");
    else
        printf("%lld\n", ans);
    return 0;
}