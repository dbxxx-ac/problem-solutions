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

const int maxk = 25;
const int maxn = int(1e4 + 5) * (maxk + 1) + 5;
const int maxm = int(5e4 + 5) * (maxk * 4 + 2) + maxk + 5;

struct edge {
    int to, nxt, w;
}e[maxm];
int head[maxn], ecnt = 0;
inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

std :: priority_queue <std :: pair <int, int> > q;

int dis[maxn];

void dijkstra(int s) {
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

int main() {
    int n = read(), m = read(), k = read(), s = 1, t = n;
    while (m--) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
        for (int i = 1; i <= k; ++i) {
            int nu = u + i * n, nv = v + i * n;
            int pu = nu - n, pv = nv - n;
            add_edge(nu, nv, w);
            add_edge(nv, nu, w);
            add_edge(pv, nu, 0);
            add_edge(pu, nv, 0);
        }
    }

    for (int i = 0; i < k; ++i) {
        add_edge(t + i * n, t + k * n, 0);
    }

    std :: memset(dis, 0x3f, sizeof(dis));
    dijkstra(s);
    printf("%d\n", dis[t + k * n]);
    return 0;
}

/*
5 6 1
0 4
0 1 5
1 2 5
2 3 5
3 4 5
2 3 3
0 2 100
*/