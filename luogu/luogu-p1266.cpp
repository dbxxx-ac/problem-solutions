/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-26 09:04:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-26 09:50:46
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

const int maxn = 155;
const int maxm = maxn * maxn;
const int maxv = 505;

struct edge {
    int to, nxt, vel, s;
}e[maxm];

int head[maxn], ecnt = 0;

double dis[maxn][maxv];
std :: pair <int, int> fa[maxn][maxv];

void add_edge(int u, int v, int vel, int w) {
    e[++ecnt] = (edge){v, head[u], vel, w};
    head[u] = ecnt;
}

std :: priority_queue <std :: pair <double, std :: pair <int, int> > > q;

void dijkstra() {
    dis[0][70] = 0;
    q.push(std :: make_pair(0.0, std :: make_pair(0, 70)));
    while (!q.empty()) {
        double d = q.top().first;
        int u = q.top().second.first;
        int vel = q.top().second.second;
        q.pop();

        if (d + dis[u][vel] != 0)
            continue;
        printf("%d %d\n", u, vel);
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            int nowvel = e[i].vel;
            if (nowvel == 0)
                nowvel = vel;
            double s = e[i].s;
            double t = s * 1.0 / nowvel;
            if (dis[v][nowvel] > dis[u][vel] + t) {
                dis[v][nowvel] = dis[u][vel] + t;
                fa[v][nowvel] = std :: make_pair(u, vel);
                q.push(std :: make_pair(-dis[v][nowvel], std :: make_pair(v, nowvel)));
            }
        }
    }
}

inline void print(int u, int vel) {
    if (u == 0)
        return ;
    print(fa[u][vel].first, fa[u][vel].second);
    printf("%d ", u);
}

int main() {
    int n = read(), m = read(), d = read();
    while (m--) {
        int a = read(), b = read(), v = read(), l = read();
        add_edge(a, b, v, l);
        add_edge(b, a, v, l);
    }
    std :: memset(dis, 0x3f, sizeof(dis));
    dijkstra();
    int minv = 1;
    for (int vel = 2; vel <= 500; ++vel) {
        if (dis[d][vel] < dis[d][minv])
            minv = vel;
    }
    printf("0 ");
    print(d, minv);
    return 0;
}