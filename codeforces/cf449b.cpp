/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-18 19:32:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-18 20:19:02
 */
#include <bits/stdc++.h>
#define int long long
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
const int maxk = (int)1e5 + 5;
int dis[maxn], cnt[maxn];
int spv[maxk], spw[maxk];
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

inline void dijkstra() {
    std :: memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    cnt[1] = 1;
    std :: priority_queue <pii> q;
    q.push({0, 1});
    
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u])
            continue;
        for (pii e : G[u]) {
            int v = e.first, w = e.second;
            if (dis[v] == dis[u] + w) {
                ++cnt[v];
            } else if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = 1;
                q.push({-dis[v], v});
            }
        }
    }
}

signed main() {
    read();
    int m = read(), k = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for (int i = 1; i <= k; ++i) {
        int u = spv[i] = read(), w = spw[i] = read();
        G[1].push_back({u, w});
        G[u].push_back({1, w});
    }

    dijkstra();
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        int u = spv[i], w = spw[i];
        if (w > dis[u])
            ++ans;
        else if (w == dis[u] && cnt[u] > 1) {
            ++ans;
            --cnt[u];
        }
    }
    printf("%lld\n", ans);
    return 0;
}