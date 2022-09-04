/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-05 17:49:42 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-05 19:35:48
 */
#include <bits/stdc++.h>

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

const int maxn = 100005;
const int maxm = 200005;

struct edge {
    int to, nxt, w;
}e[maxm * 2];

int head[maxn], ecnt = 1;

inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

int dis1[maxn], disn[maxn];
std :: priority_queue <std :: pair <int, int> > q;

void dijkstra(int* dis, int s) {
    q.emplace(0, s);
    dis[s] = 0;
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(-dis[v], v);
            }
        }
    }
}

int l[maxn], r[maxn], z[maxn];
bool p[maxm];

std :: basic_string <int> f[maxn], g[maxn];
std :: multiset <int> s;

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    std :: memset(dis1, 0x3f, sizeof(dis1));
    std :: memset(disn, 0x3f, sizeof(disn));
    dijkstra(dis1, 1);
    dijkstra(disn, n);

    std :: memset(l, 0x3f, sizeof(l));
    l[1] = 1;
    int k = 0;
    
    for (int u = 1; u != n;) {
        for (int i = head[u]; i; i = e[i].nxt) {
            if (disn[e[i].to] + e[i].w == disn[u]) {
                u = e[i].to;
                p[i >> 1] = true;
                break;
            }
        }
        r[u] = ++k;
        l[u] = k + 1;
    }

    std :: iota(z + 1, z + 1 + n, 1);

    std :: sort(z + 1, z + 1 + n, [](int x, int y) {
        return dis1[x] < dis1[y];
    });

    for (int i = 1; i <= n; ++i) {
        int u = z[i];
        for (int j = head[u]; j; j = e[j].nxt) {
            if (p[j >> 1])
                continue;
            int v = e[j].to, w = e[j].w;
            if (dis1[v] == dis1[u] + w && l[v] > l[u])
                l[v] = l[u];
        }
    }

    std :: sort(z + 1, z + 1 + n, [](int x, int y) {
        return disn[x] < disn[y];
    });

    for (int i = 1; i <= n; ++i) {
        int u = z[i];
        for (int j = head[u]; j; j = e[j].nxt) {
            if (p[j >> 1])
                continue;
            int v = e[j].to, w = e[j].w;
            if (disn[v] == disn[u] + w && r[v] < r[u])
                r[v] = r[u];
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (p[i])
            continue;
        int u = e[i << 1 | 1].to, v = e[i << 1].to, w = e[i << 1].w;
        if (l[u] <= r[v]) {
            int d = dis1[u] + w + disn[v];
            f[l[u]] += d;
            g[r[v]] += d;
        }
        if (l[v] <= r[u]) {
            int d = dis1[v] + w + disn[u];
            f[l[v]] += d;
            g[r[u]] += d;
        }
    }

    int ans = 0, cnt = 0;

    for (int i = 1; i <= k; ++i) {
        for (int d : f[i])
            s.insert(d);
        int cur = *s.begin();
        if (cur >= ans) {
            if (cur > ans) {
                ans = cur;
                cnt = 0;
            }
            ++cnt;
        }
        for (int d : g[i])
            s.erase(s.find(d));
    }

    if (ans == dis1[n])
        cnt = m;
    printf("%d %d\n", ans, cnt);
    return 0;
}

/*
3 4
1 2 1
1 2 2
2 3 1
2 3 2
*/