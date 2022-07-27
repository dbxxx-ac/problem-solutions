/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-26 09:04:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-27 09:15:16
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
const double eps = 1e-6;

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

        if (std :: fabs(d + dis[u][vel]) > eps)
            continue;
        // printf("%d %d\n", u, vel);
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            int nowvel = e[i].vel;
            if (nowvel == 0)
                nowvel = vel;
            double s = e[i].s;
            double t = double(s) * 1.0 / double(nowvel);
            // printf("%d %d %d %f %f %f\n", u, vel, nowvel, t, dis[v][nowvel], dis[u][vel] + t);
            
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
    // printf("%d %d ", fa[u][vel].first, fa[u][vel].second);
    print(fa[u][vel].first, fa[u][vel].second);
    printf("%d ", u);
    // puts("");
}

int main() {
    int _ = read(), m = read(), d = read();
    while (m--) {
        int a = read(), b = read(), v = read(), l = read();
        add_edge(a, b, v, l);
        // add_edge(b, a, v, l);
    }
    std :: memset(dis, 0x42, sizeof(dis));
    dijkstra();
    int minv = 1;
    for (int vel = 2; vel <= 500; ++vel) {
        if (dis[d][vel] < dis[d][minv])
            minv = vel;
    }
    printf("0 ");
    print(d, minv);
    puts("");
    return 0;
}

/*
6 15 1
0 1 25 68
0 2 30 50
0 5 0 101
1 2 70 77
1 3 35 42
2 0 0 22
2 1 40 86
2 3 0 23
2 4 45 40
3 1 64 14
3 5 0 23
4 1 95 8
5 1 0 84
5 2 90 64
5 3 36 40
*/