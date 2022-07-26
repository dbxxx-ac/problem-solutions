/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-13 01:58:27 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-13 10:57:25
 */
#include <bits/stdc++.h>
#define int long long

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

const int maxn = 1e4 + 5;
const int maxm = 5e4 + 5;
const int maxf = 1e9 + 5;
int f[maxn];

struct edge{
    int to, nxt, w;
}e[maxm * 2];
int head[maxn], ecnt = 0;
inline void add_edge(int u, int v, int w) {
    e[++ecnt].to = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
}

int dis[maxn], n, b;
std :: priority_queue <std :: pair <int, int> > q;

bool check(int x) {
    if (x < f[1])
        return true;
    std :: memset(dis, 0x1f, sizeof(dis));
    dis[1] = 0;
    q.push(std :: make_pair(0LL, 1LL));
    
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (f[v] <= x && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(std :: make_pair(-dis[v], v));
            }
        }
    }

    return dis[n] > b;
}

signed main() {
    n = read();
    int m = read();
    b = read();
    for (int i = 1; i <= n; ++i)
        f[i] = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    if (check(maxf)) {
        puts("AFK");
        return 0;
    }

    int ans = 0;
    for (int i = (1LL << 30); i >= 1LL; i >>= 1LL)
        if (check(ans + i))
            ans += i;
    printf("%lld\n", ans + 1);
    return 0;
}