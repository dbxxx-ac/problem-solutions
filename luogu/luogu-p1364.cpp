/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-01 22:01:07 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-02 17:04:35
 */
//找树的重心，学习于P1364第一篇题解。
#include <iostream>
#include <cstdio>
#include <climits>

const int maxn = 105;

struct Edge {
    int v, nxt;
}edge[maxn << 1];

int w[maxn];
int head[maxn], idx, n, siz[maxn];
int ans = INT_MAX >> 2, dp[maxn];

inline void addEdge(int u, int v) {
    edge[++idx].v = v;
    edge[idx].nxt = head[u];
    head[u] = idx;
}

void dfs(int u, int father, int depth) {
    siz[u] = w[u];
    for (int i = head[u]; i; i = edge[i].nxt) 
        if (edge[i].v != father) {
            dfs(edge[i].v, u, depth + 1);
            siz[u] += siz[edge[i].v];
        }
    dp[1] += w[u] * depth;
}

void work(int u, int father) {
    for (int i = head[u]; i; i = edge[i].nxt)
        if (edge[i].v != father) {
            dp[edge[i].v] = dp[u] - siz[edge[i].v] * 2 + siz[1];
            work(edge[i].v, u);
        }
    ans = ans < dp[u] ? ans : dp[u];
}

int main(){
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        std :: scanf("%d", &w[i]);
        int a, b;
        std :: scanf("%d%d", &a, &b);
        if (a) {
            addEdge(a, i);
            addEdge(i, a);
        }
        if (b) {
            addEdge(b, i);
            addEdge(i, b);
        }
    }
    dfs(1, 0, 0);
    work(1, 0);
    printf("%d", ans);
    return 0;
}