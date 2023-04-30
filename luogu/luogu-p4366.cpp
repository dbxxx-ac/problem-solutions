/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-17 18:23:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-17 19:15:10
 */

// O2 needed

#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

const int maxn = (int)1e5 + 5;
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int dis[maxn];

inline int dijkstra(int s, int t) {
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    std :: priority_queue <pii> q;
    q.push({0, s});

    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u])
            continue;
        
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }

    return dis[t];
}

int main() {
    int n = read(), m = read(), c = read();
    for (int u = 0; u <= n; ++u)
        for (int i = 1; i <= n; i <<= 1)
            if ((u ^ i) <= n)
                G[u].push_back({u ^ i, i * c});
    while (m--) {
        int u = read(), v = read(), w = read();
        G[u].push_back({v, w});
    }

    int s = read(), t = read();
    printf("%d\n", dijkstra(s, t));
    return 0;
}