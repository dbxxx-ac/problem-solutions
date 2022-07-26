/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-25 20:54:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-25 21:12:56
 */
#include <iostream>
#include <climits>
#include <cstdio>
#include <queue>

const int maxn = 100005;
const int maxm = 500005;

struct edge {
    int to, nxt, dis;
}e[maxm];

int head[maxn], cnt;
int dis[maxn];
bool vis[maxn];

int n, m, s;

struct sorted_edge {
    int pos;
    int dis;
    bool operator < (const sorted_edge& b) const {
        return this -> dis > b.dis;
    }
};

std :: priority_queue <sorted_edge> q;

inline void add_edge(int u, int v, int dis) {
    e[++cnt].dis = dis;
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

inline void dijkstra() {
    dis[s] = 0;
    q.push((sorted_edge){s, 0});

    while (!q.empty()) {
        int u = q.top().pos;
        q.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (dis[v] > dis[u] + e[i].dis) {
                    dis[v] = dis[u] + e[i].dis;
                    if (!vis[v])
                        q.push((sorted_edge){v, dis[v]});
                }
            }
        }
    }
}

int main() {
    std :: scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; ++i)
        dis[i] = 0x7fffffff;
    
    for (int i = 1; i <= m; ++i) {
        int u, v, dis;
        std :: scanf("%d %d %d", &u, &v, &dis);
        add_edge(u, v, dis);
    }


    dijkstra();

    for (int i = 1; i <= n; ++i)
        std :: printf("%d ", dis[i]);
    return 0;
}