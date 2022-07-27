/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-27 09:38:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-27 11:30:13
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

const int maxr = int(1e3);
const int maxc = int(1e3);
const int maxn = maxr * maxc * 2 + 5;
const int maxm = maxr * maxc * 6 + maxr * 2 + maxc * 2 + 5;

struct edge {
    int to, nxt, w;
}e[maxm];

int head[maxn], ecnt = 0;

inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

int n, m;
inline int tri(int x, int y, int op) {
    return (x - 1) * m * 2 + y * 2 - op;
}

std :: priority_queue <std :: pair <int, int> > q;
int dis[maxn];

void dijkstra() {
    q.emplace(0, 0);
    dis[0] = 0;
    while (!q.empty()) {
        // printf("%d\n", q.top().second);
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

int main() {
    n = read() - 1;
    m = read() - 1;
    int t = n * m * 2 + 1;

    for (int i = 1; i <= m; ++i) {
        int x = read();
        add_edge(tri(1, i, 0), t, x);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = read();
            int u = tri(i - 1, j, 1), v = tri(i, j, 0);
            add_edge(u, v, x);
            add_edge(v, u, x);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x = read();
        add_edge(0, tri(n, i, 1), x);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = read();
            if (j == 1) {
                add_edge(0, tri(i, 1, 1), x);
            } else {
                int u = tri(i, j - 1, 0), v = tri(i, j, 1);
                add_edge(u, v, x);
                add_edge(v, u, x);
            }
        }
        int x = read();
        add_edge(tri(i, m, 0), t, x);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = read();
            int u = tri(i, j, 0), v = tri(i, j, 1);
            add_edge(u, v, x);
            add_edge(v, u, x);
        }
    }

    std :: memset(dis, 0x3f, sizeof(dis));
    dijkstra();
    printf("%d\n", dis[t]);
    return 0;
}

/*
3 4
5 6 4
4 3 1
7 5 3
5 6 7 8
8 7 6 5
5 5 5
6 6 6

3 3
2 100
100 2
2 100
100 2 100
100 2 100
100 100
2 2

*/