/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-08 22:56:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-08 23:23:56
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

int wei[maxm];

typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];

int dis[maxn], pre[maxn];

void dijkstra(int s) {
    std :: memset(dis, 0x3f, sizeof(dis));
    std :: priority_queue <pii> q;
    dis[s] = 0;
    q.emplace(0, s);

    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        
        for (pii e : G[u]) {
            int v = e.first, id = e.second, w = wei[id];
            if (dis[v] >= dis[u] + w) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.emplace(-dis[v], v);
                }
                pre[v] = id;
            }
        }
    }
}

signed main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        wei[i] = read();
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    int s = read();

    dijkstra(s); 

    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == s)
            continue;
        sum += wei[pre[i]];
    }

    printf("%lld\n", sum);

    for (int i = 1; i <= n; ++i) {
        if (i == s)
            continue;
        printf("%lld ", pre[i]);
    }

    return 0;
}