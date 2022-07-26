/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-07 11:50:00 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-07 12:02:07
 */
#include <bits/stdc++.h>

const int maxn = 155;
const int maxm = 5005;
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) return x;
    return ~(x - 1);
}

struct edge {
    int u, v, nxt;
}e[maxm];

int head[maxn], ecnt = 0;

inline void insert(int u, int v) {
    e[++ecnt] = (edge){u, v, head[u]};
    head[u] = ecnt;
}

int times = 0;
int dfn[maxn], low[maxn];
int bcc_cnt = 0, cut_cnt = 0;
bool iscut[maxn];
std :: set <int> bcc[maxn];
std :: stack <edge> S;

void dfs(int u, int fa) {
    dfn[u] = low[u] = ++times;
    int child = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (dfn[v] == 0) {
            S.push(e[i]);
            ++child;
            dfs(v, u);
            low[u] = std :: min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                iscut[u] = true;
                ++bcc_cnt;
                for (;;) {
                    edge x = S.top();
                    S.pop();
                    bcc[bcc_cnt].insert(x.u);
                    bcc[bcc_cnt].insert(x.v);
                    if (x.u == u && x.v == v)
                        break;
                }
            } else if (dfn[v] < dfn[u] && v != fa) {
                S.push(e[i]);
                low[u] = std :: min(low[u], dfn[v]);
            }
        }
    }

    if (fa < 0 && child == 1)
        iscut[u] = false;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        insert(u, v);
        insert(v, u);
    }
    
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            dfs(i, -1);

    for (int i = 1; i <= n; ++i)
        if (iscut[i])
            ++cut_cnt;
    
    std :: printf("%d\n", cut_cnt);
    for (int i = 1; i <= n; ++i)
        if (iscut[i])
            std :: printf("%d\n", i);
    return 0;
}