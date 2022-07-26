/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-05 17:08:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-05 18:13:34
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>

const int maxn = 30005;
const int maxm = 60005;
const long long maxinf = (int)1e9;
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) return x;
    return ~(x - 1);
}
inline int min(int a, int b) {
    return a < b ? a : b;
}

int n, m;
int head[maxn], cnt = 0;
long long h[maxn], dis[maxn];
bool vis[maxn];
struct edge {
    int nxt, to, val;
}e[maxm];
void insert(int u, int v, int w) {
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    e[cnt].val = w;
    head[u] = cnt;
    return ;
}

int sum[maxn];
int BF() {
    std :: queue <int> q;
    std :: memset(h, 100, sizeof(h));
    std :: memset(vis, false, sizeof(vis));
    h[0] = 0;
    vis[0] = true;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (++sum[u] >= n + 1)
            return -1;
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].val;
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return 1;
}

void dijkstra(int s) {
    std :: priority_queue <std :: pair<long long, int> >q;
    for (int i = 1; i <= n; ++i)
        dis[i] = maxinf;
    std :: memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    q.push(std :: make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to, w = e[i].val;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                        q.push(std :: make_pair(-dis[v], v));
                }
            }
        }
    }
    return ;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        insert(u, v, w);
    }
    for (int i = 1; i <= n; ++i)
        insert(0, i, 0);
    
    if (BF() == -1) {
        puts("-1");
        return 0;
    }

    for (int u = 1; u <= n; ++u)
        for (int i = head[u]; i; i = e[i].nxt)
            e[i].val += h[u] - h[e[i].to];
    
    for (int u = 1; u <= n; ++u) {
        dijkstra(u);
        long long ans = 0;
        for (int v = 1; v <= n; ++v) {
            long long d;
            if (dis[v] == maxinf)
                d = maxinf;
            else
                d = dis[v] + h[v] - h[u];
            ans += (long long)v * d;
        }
        std :: printf("%lld\n", ans);
    }
    
    return 0;
}