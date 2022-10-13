/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-07 20:40:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-07 23:25:53
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

inline bool updmin(int &x, int y) {
    return y < x ? x = y, true : false;
}

const int maxn = 505;
const int maxm = 505;
const int maxk = 55;
const int maxv = maxn * maxm + maxn + maxm + maxk; // 这个是最大点数（到不了），随便搞的不要太当真
const int inf = 0x3f3f3f3f;

struct edge {
    int nxt, v, w;
}e[maxn * maxm * 12]; // 12 是随便写的，保证不炸

int head[maxv], ecnt = 0; // 随便搞的不要太当真
int org[maxv];

inline void dda_edge(int u, int v, int w) {
    e[++ecnt] = (edge){head[u], v, w};
    head[u] = ecnt;
    e[++ecnt] = (edge){head[v], u, w};
    head[v] = ecnt;
}

int h[maxn][maxm];

struct node {
    int w, p, t;
}a[maxk];

int n, m;

inline int pr(int p) {
    if (p <= m)
        return h[0][p - 1];
    else if (p <= n + m)
        return h[p - m - 1][m];
    else if (p <= 2 * m + n)
        return h[n][2 * m + n - p + 1];
    else
        return h[2 * m + 2 * n - p + 1][0];
}

inline int nx(int p) {
    if (p <= m)
        return h[0][p];
    else if (p <= n + m)
        return h[p - m][m];
    else if (p <= 2 * m + n)
        return h[n][2 * m + n - p];
    else
        return h[2 * m + 2 * n - p][0];
}

inline void con(int p, int w) {
    dda_edge(pr(p), nx(p), w);
    return ;
}

inline void con2(int p, int q, int w) {
    dda_edge(nx(p), q, w);
}

int f[maxk << 1][maxk << 1];
int g[maxk << 1][maxk << 1];
int dis[maxv];

// #define debug
// #define debug2

int main() {
    n = read();
    m = read();
    int T = read();
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            h[i][j] = i * (m + 1) + j + 1;
    
    int znt = (m + 1) * (n + 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int w = read();
            dda_edge(h[i][j - 1], h[i][j], w);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            int w = read();
            dda_edge(h[i - 1][j], h[i][j], w);
        }
    }

    int zet = ecnt;

    std :: memcpy(org, head, sizeof(head));
    
    #ifdef debug2
        puts("done");
    #endif
    
    while (T--) {
        int k = read();
        int z = 0;
        #ifdef debug
        printf("%d\n", k);
        #endif
        
        bool skip = true;
        for (int i = 1; i <= k; ++i) {
            int w = read(), p = read(), t = read();
            a[i] = (node){w, p, t};
            if (i > 1 && a[i].t != a[i - 1].t)
                skip = false;
        }

        #ifdef debug
            puts("done2");
        #endif
        
        if (skip) {
            puts("0");
            continue; // 如果都同色直接跳过，否则后面会出一点问题（区间dp需要特判，不想那么做）
        }

        std :: sort(a + 1, a + 1 + k, [](node x, node y) {
            return x.p < y.p;
        });
        
        for (int i = 1; i < a[1].p; ++i)
            con(i, 0);

        for (int i = 1; i < k; ++i) {
            int p = a[i].p, w = a[i].w, t = a[i].t;
            int np = a[i + 1].p, nt = a[i + 1].t;
            con(p, w);
            for (int j = p + 1; j < np; ++j)
                con(j, 0);
            
            if (t != nt) {
                ++z;
                for (int j = p; j < np; ++j)
                    con2(j, znt + z, 0);
            }
        }

        con(a[k].p, a[k].w);
        for (int i = a[k].p + 1; i <= n * 2 + m * 2; ++i)
            con(i, 0);
        
        if (a[k].t != a[1].t) {
            ++z;
            for (int j = a[k].p; j <= n * 2 + m * 2; ++j)
                con2(j, znt + z, 0);
            for (int j = 1; j < a[1].p; ++j)
                con2(j, znt + z, 0);
        }
        
        std :: priority_queue <std :: pair <int, int> > q;

        for (int s = znt + 1; s < znt + z; ++s) {
            std :: memset(dis, 0x3f, sizeof(dis));
            dis[s] = 0;
            q.emplace(0, s);

            while (!q.empty()) {
                int d = q.top().first, u = q.top().second;
                q.pop();
                if (d + dis[u] != 0)
                    continue;
                for (int i = head[u]; i; i = e[i].nxt) {
                    int v = e[i].v, w = e[i].w;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        q.emplace(-dis[v], v);
                    }
                }
            }

            for (int i = s + 1; i <= znt + z; ++i) {
                int p = s - znt, q = i - znt;
                g[p][q] = g[p][q + z] = g[q][p + z] = g[p + z][q + z] = dis[i];
            }
        }

        for (int i = 1; i <= z * 2; ++i)
            f[i][i - 1] = 0;

        for (int len = 2; len <= z; len += 2) {
            for (int l = 1, r = len; r <= z * 2; ++l, ++r) {
                f[l][r] = f[l + 1][r - 1] + g[l][r];
                for (int i = l + 1; i < r; i += 2)
                    updmin(f[l][r], f[l][i] + f[i + 1][r]);
            }
        }

        int ans = inf;
        for (int l = 1, r = z; r <= z * 2; ++l, ++r)
            updmin(ans, f[l][r]);
        
        printf("%d\n", ans);

        ecnt = zet;
        std :: memcpy(head, org, sizeof(org));
    }
    return 0;
}