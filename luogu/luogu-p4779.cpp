/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-13 00:02:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-13 00:11:22
 */
#include <bits/stdc++.h>

inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

int head[maxn];
struct edge {
    int to, nxt, w;
}e[maxm];
int ecnt = 0;

inline void add_edge(int u, int v, int w) {
    e[++ecnt].to = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
}

int n, m, s;
std :: priority_queue <std :: pair <int, int> > q;

int dis[maxn];

void dijkstra() {
    q.push(std :: make_pair(0, s));
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
                q.push(std :: make_pair(-dis[v], v));
            }
        }
    }
}

int main() {
    n = read();
    m = read();
    s = read();
    for (int _ = 1; _ <= m; ++_) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
    }

    std :: memset(dis, 0x3f, sizeof(dis));
    dijkstra();
    for (int i = 1; i <= n; ++i)
        printf("%d ", dis[i]);
    puts("");
    return 0;
}