/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-27 18:42:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-27 20:39:35
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

const int maxn = int(1e5) + 5;
const int maxk = maxn;
const int maxm = int(5e5) + 5;

struct edge {
    int to, nxt, w;
}e[maxm];

int head[maxn], ecnt = 0;

inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

int c[2][maxn], fav[maxk];
long long dis[2][maxn];

int k;

std :: priority_queue <std :: pair <long long, int> > q;

void dijkstra(long long *dis, int *c) {
    for (int i = 1; i <= k; ++i) {
        dis[fav[i]] = 0;
        c[fav[i]] = fav[i];
        q.emplace(0, fav[i]);
    }
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                c[v] = c[u];
                q.emplace(-dis[v], v);
            }
        }
    }
}

int edu[maxm], edv[maxm], edw[maxm];

void init() {
    std :: memset(head, 0, sizeof(head));
    ecnt = 0;
}

int main() {
    int T = read();
    while (T--) {
        init();
        int n = read(), m = read();
        k = read();
        for (int i = 1; i <= m; ++i) {
            edu[i] = read();
            edv[i] = read();
            edw[i] = read();
            add_edge(edu[i], edv[i], edw[i]);
        }

        for (int i = 1; i <= k; ++i)
            fav[i] = read();
        
        std :: memset(dis, 0x3f, sizeof(dis));
        dijkstra(dis[0], c[0]);
        init();
        for (int i = 1; i <= m; ++i) {
            add_edge(edv[i], edu[i], edw[i]);
        }

        dijkstra(dis[1], c[1]);

        long long ans = LONG_LONG_MAX;
        for (int i = 1; i <= m; ++i) {
            int u = edu[i], v = edv[i], w = edw[i];
            if (c[0][u] != 0 && c[1][v] != 0 && c[0][u] != c[1][v]) {
                ans = std :: min(dis[0][u] + dis[1][v] + w, ans);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}


/*
另一种解法：依据位运算的思想，跑 log k 次最短路。
O2 可过，朴素无法通过

 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-27 16:04:52 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-27 18:41:36

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

const int maxn = int(1e5) + 5;
const int maxk = maxn;
const int maxm = int(5e5) + 5 + maxk * 5;

struct edge {
    int to, nxt, w;
}e[maxm];

int head[maxn], ecnt = 0;
int org[maxk];
inline void add_edge(int u, int v, int w) {
    e[++ecnt] = (edge){v, head[u], w};
    head[u] = ecnt;
}

int fav[maxk];
long long dis[maxn];

std :: priority_queue <std :: pair <long long, int> > q;

void dijkstra(int s) {
    q.emplace(0LL, s);
    dis[s] = 0;
    while (!q.empty()) {
        long long d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d + dis[u] != 0)
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(-dis[v], v);
            }
        }
    }
}

int main() {
    int T = read();
    while (T--) {
        ecnt = 0;
        std :: memset(head, 0, sizeof(head));
        int n = read(), m = read(), k = read();
        while (m--) {
            int u = read(), v = read(), w = read();
            add_edge(u, v, w);
        }
        for (int i = 1; i <= k; ++i)
            fav[i] = read();
        
        int s = 0, t = n + 1;
        long long ans = LONG_LONG_MAX;
        for (int i = 0; (1 << i) <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                org[j] = head[fav[j]];
                if ((j >> i) & 1)
                    add_edge(s, fav[j], 0);
                else
                    add_edge(fav[j], t, 0);
            }
            std :: memset(dis, 0x3f, sizeof(dis));
            // puts("OK");
            dijkstra(s);
            // printf("OK");
            //  printf("%lld\n", dis[t]);
            if (ans > dis[t])
                ans = dis[t];
            ecnt -= k;
            head[s] = 0;
            for (int j = 1; j <= k; ++j)
                head[fav[j]] = org[j];
            
            for (int j = 1; j <= k; ++j) {
                if ((j >> i) & 1)
                    add_edge(fav[j], s, 0);
                else
                    add_edge(t, fav[j], 0);
            }
            std :: memset(dis, 0x3f, sizeof(dis));
            // puts("OK");
            dijkstra(t);
            // printf("OK");
            //  printf("%lld\n", dis[t]);
            if (ans > dis[s])
                ans = dis[s];
            ecnt -= k;
            head[t] = 0;
            for (int j = 1; j <= k; ++j)
                head[fav[j]] = org[j];
            
        }
        printf("%lld\n", ans);
    }
    return 0;
}

2
6 7 3
1 5 3
2 3 5
1 4 3
5 3 2
4 6 5
4 3 7
5 6 4
1 3 6

7 7 4
5 3 10
6 2 7
1 2 6
5 4 2
4 3 4
1 7 3
7 2 4
1 2 5 3
*/
