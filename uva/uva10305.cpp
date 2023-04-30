/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-19 22:34:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-19 23:27:09
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

const int maxn = 105;
int flag[maxn];
std :: vector <int> topo;
std :: vector <int> G[maxn];
int n, m;

bool dfs(int u) {
    flag[u] = -1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (flag[v] == -1) return false;
        else if (flag[v] == 0) {
            if (!dfs(v)) return false;
        }
    }
    flag[u] = 1;
    topo.push_back(u);
    return true;
}

bool toposort() {
    topo.clear();
    for (int i = 1; i <= n; ++i) flag[i] = 0;
    for (int i = 1; i <= n; ++i) {
        if (flag[i] == 0) {
            if (!dfs(i)) return false;
        }
    }
    std :: reverse(topo.begin(), topo.end());
    return true;
}


int main() {
    while (~std :: scanf("%d %d", &n, &m) && (n || m)) {
        for (int i = 0; i < maxn; ++i) G[i].clear();
        for (int i = 1, u, v; i <= m; ++i) {
            std :: scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }

        if (!toposort()) std :: printf("Are you thinking peach\n");
        else {
            for (int i = 0; i < n; ++i)
                std :: printf("%d ", topo[i]);
        }
        putc('\n', stdout);
    }
}