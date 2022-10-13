/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-22 20:49:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-22 21:16:36
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

const int maxn = (int)1e4 + 5;

std :: vector <int> g[maxn];
int val[maxn];
int dfn[maxn], low[maxn], scc[maxn], siz[maxn];
int times = 0, snt = 0;

std :: stack <int> s;

inline bool getmin(int &a, int b) {
    return b < a ? a = b, true : false;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++times;
    s.push(u);

    for (auto v : g[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            getmin(low[u], low[v]);
        } else if (scc[v] == 0)
            getmin(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        ++snt;
        for (; ;) {
            int x = s.top();
            s.pop();
            siz[snt] += val[x];
            scc[x] = snt;
            if (x == u)
                break;
        }
    }
}

std :: vector <int> G[maxn];

int ind[maxn], dis[maxn];

inline bool getmax(int &a, int b) {
    return b > a ? a = b, true : false;
}

inline int topsort(int n) {
    std :: queue <int> q;
    
    for (int u = 1; u <= n; ++u) if (ind[u] == 0) {
        q.push(u);
        dis[u] = siz[u];
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto v : G[u]) {
            --ind[v];
            getmax(dis[v], dis[u] + siz[v]);
            if (ind[v] == 0)
                q.push(v);
        }
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u)
        getmax(ans, dis[u]);
    return ans;
}

const int maxm = (int)1e5 + 5;
struct edge {
    int u, v;
}e[maxm];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        val[i] = read();
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        g[u].push_back(v);
        e[i] = (edge){u, v};
    }

    for (int u = 1; u <= n; ++u)
        if (dfn[u] == 0)
            tarjan(u);
    
    // for (int u = 1; u <= n; ++u)
    //     printf("%d ", scc[u]);
    // puts("");
    
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v;
        u = scc[u];
        v = scc[v];
        if (u == v)
            continue;
        G[u].push_back(v);
        ++ind[v];
    }

    printf("%d\n", topsort(n));
    return 0;
}