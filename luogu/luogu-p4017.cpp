/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-24 01:02:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-24 01:07:25
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

const int maxn = 5005;
const int mod = 80112002;

bool eated[maxn];
int ind[maxn], dp[maxn];
int n, m;
std :: vector <int> G[maxn];

void toposort() {
    std :: queue <int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            dp[v] = (dp[v] + dp[u]) % mod;
            --ind[v];
            if (ind[v] == 0) q.push(v);
        }
    }
}

int main() {
    std :: scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std :: scanf("%d%d", &u, &v);
        G[u].push_back(v);
        ++ind[v];
        eated[u] = true;
    }

    toposort();

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!eated[i])
            ans = (ans + dp[i]) % mod;
    }

    std :: printf("%d\n", ans);
}