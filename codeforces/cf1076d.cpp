/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-08 23:43:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-08 23:56:35
 */
#include <bits/stdc++.h>

#define int long long

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

const int maxn = (int)3e5 + 5;
const int maxm = (int)3e5 + 5;

typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];
int dis[maxn], pre[maxn], wei[maxm];

inline void dijkstra(int k) {
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    std :: priority_queue <pii> q;
    q.emplace(0, 1);

    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        
        if (u != 1) {
            printf("%lld ", pre[u]);
            --k;
        }
        if (k == 0)
            return ;
        for (pii e : G[u]) {
            int v = e.first, id = e.second, w = wei[id];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = id;
                q.emplace(-dis[v], v);
            }
        }
    }
}

signed main() {
    int n = read(), m = read(), k = read();
    if (k > n - 1)
        k = n - 1;
    printf("%lld\n", k);

    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
        wei[i] = w;
    }

    dijkstra(k);

    return 0;
}