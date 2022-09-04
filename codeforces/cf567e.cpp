/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-15 18:31:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-15 21:10:14
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

const int maxn = (int)1e5 + 5;
const int maxm = (int)1e5 + 5;
const int mod1 = 998244353;
const int mod2 = 192608173;
const int inf = (int)1e18 + 5;

struct G {
    int head[maxn], ecnt = 0;
    struct edge {
        int u, v, w, nxt;
    }e[maxm];

    inline void add_edge(int u, int v, int w) {
        e[++ecnt] = (edge){u, v, w, head[u]};
        head[u] = ecnt;
    }

    int cnt1[maxn], cnt2[maxn], dis[maxn];

    void dijkstra(int s) {
        std :: priority_queue <std :: pair <int, int> > q;
        q.emplace(0, s);
        dis[s] = 0;
        cnt1[s] = cnt2[s] = 1;
        while (!q.empty()) {
            int d = q.top().first, u = q.top().second;
            q.pop();
            if (d + dis[u] != 0)
                continue;
            
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].v, w = e[i].w;
                if (dis[v] == dis[u] + w) {
                    (cnt1[v] += cnt1[u]) %= mod1;
                    (cnt2[v] += cnt2[u]) %= mod2;
                } else if (dis[v] > dis[u] + w) {
                    cnt1[v] = cnt1[u];
                    cnt2[v] = cnt2[u];
                    dis[v] = dis[u] + w;
                    q.emplace(-dis[v], v);
                }
            }
        }
    }

    G() {
        std :: memset(this, 0, sizeof(G));
        std :: memset(dis, 0x3f, sizeof(dis));
    }
} gr, re;

signed main() {
    int n = read(), m = read(), s = read(), t = read();
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        gr.add_edge(u, v, w);
        re.add_edge(v, u, w);
    }

    gr.dijkstra(s);
    re.dijkstra(t);
    
    for (int i = 1; i <= m; ++i) {
        G :: edge now = gr.e[i];
        int u = now.u, v = now.v, w = now.w;

        if (gr.dis[u] >= inf || re.dis[v] >= inf) {
            puts("NO");
        } else if (gr.dis[u] + w + re.dis[v] == gr.dis[t]
            && gr.cnt1[u] * re.cnt1[v] % mod1 == gr.cnt1[t]
            && gr.cnt2[u] * re.cnt2[v] % mod2 == gr.cnt2[t]) {
                puts("YES");
        } else {
            int x = gr.dis[u] + w + re.dis[v] - gr.dis[t] + 1;
            if (x < w)
                printf("CAN %lld\n", x);
            else
                puts("NO");
        }
    }

    return 0;
}