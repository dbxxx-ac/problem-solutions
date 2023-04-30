/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-03 23:29:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-03 23:36:42
 */
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

inline void dijkstra(int s) {
    std :: priority_queue <pii> q;
    q.push({0, s});
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

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
}

int main() {
    int n = read(), m = read(), s = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        G[u].push_back({v, w});
    }

    dijkstra(s);

    for (int u = 1; u <= n; ++u)
        printf("%d ", dis[u]);
    puts("");

    return 0;
}