/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-15 15:57:19 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-15 16:17:41
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

const int maxn = 500005;
const int maxm = 500005;
const int lg = 20;

struct edge {
    int to, nxt;
}e[maxm << 1];

int head[maxn], ecnt = 0;

int far[maxn][lg], dep[maxn];

inline void add_edge(int u, int v) {
    e[++ecnt] = (edge){v, head[u]};
    head[u] = ecnt;
}

void dfs(int u, int fa) {
    far[u][0] = fa;
    dep[u] = dep[fa] + 1;
    
    for (int i = 1; i < lg; ++i)
        far[u][i] = far[far[u][i - 1]][i - 1];
    
    for (int i = head[u], v; i; i = e[i].nxt)
        if ((v = e[i].to) != fa)
            dfs(v, u);
    
    return ;
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v])
        u ^= v ^= u ^= v;

    for (int i = 0; i < lg; ++i) {
        if ((dep[u] - dep[v]) & (1 << i))
            u = far[u][i];
    }
    
    if (u == v)
        return u;
    
    for (int i = lg - 1; i >= 0; --i) {
        if (far[u][i] != far[v][i]) {
            u = far[u][i];
            v = far[v][i];
        }
    }
    
    return far[u][0];
}

int main() {
    int n = read(), m = read(), s = read();
    for (int _ = 1; _ <= n - 1; ++_) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(s, 0);
    
    while (m--) {
        int u = read(), v = read();
        printf("%d\n", lca(u, v));
    }

    return 0;
}