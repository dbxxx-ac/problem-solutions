/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-26 20:25:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-26 20:33:51
 */
#include <iostream>
#include <cstdio>
#include <vector>
int n, m, k;

const int maxk = 105;
const int maxn = 1005;
const int maxm = 10005;

int cow[maxk], can_get[maxn];
bool vis[maxn];
std :: vector <int> G[maxn];

void dfs(int u) {
    vis[u] = true;
    ++can_get[u];
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!vis[v])
            dfs(v);
    }
}

int main() {
    std :: scanf("%d %d %d", &k, &n, &m);
    for (int i = 1; i <= k; ++i)
        std :: scanf("%d", &cow[i]);
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std :: scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }

    for (int i = 1; i <= k; ++i) {
        for (int i = 1; i <= n; ++i)
            vis[i] = false;
        dfs(cow[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (can_get[i] == k)
            ++ans;
    
    std :: printf("%d\n", ans);
    return 0;
}