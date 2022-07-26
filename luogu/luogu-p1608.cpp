/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-13 00:47:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-13 01:17:22
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

const int maxn = 2005;
const int maxm = maxn * (maxn - 1);

struct edge {
    int to, nxt, w;
}e[maxm];
int ecnt = 1;
int head[maxn];
int exi[maxn][maxn];
inline void add_edge(int u, int v, int w) {
    int num = exi[u][v];
    if (num && e[num].w >= w) {
        e[num].w = w;
        return ;
    }
    e[++ecnt].to = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
    exi[u][v] = ecnt;
}

std :: priority_queue <std :: pair <int, int> > q;
int dis[maxn], ans[maxn];

void dijkstra() {
    q.push(std :: make_pair(0, 1));
    dis[1] = 0;
    ans[1] = 1;
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (dis[v] == dis[u] + w)
                ans[v] += ans[u];
            else if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                ans[v] = ans[u];
                q.push(std :: make_pair(-dis[v], v));
            }
        }
    }
}

int main() {
    int n = read(), m = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
    }
    std :: memset(dis, 0x3f, sizeof(dis));
    dijkstra();
    if (dis[n] != 0x3f3f3f3f)
        printf("%d %d\n", dis[n], ans[n]);
    else
        puts("No answer");
    return 0;
}