/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-19 11:00:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-19 11:19:46
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

const int maxn = 10005;

std :: vector <int> edge[maxn];
std :: queue <int> q;

int t[maxn], dp[maxn], ind[maxn];

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        std :: scanf("%d", &u);
        std :: scanf("%d %d", &t[u], &v);
        while (v) {
            edge[v].push_back(u);
            ++ind[u];
            std :: scanf("%d", &v);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            dp[i] = t[i];
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i];
            --ind[v];
            if (ind[v] == 0) q.push(v);
            dp[v] = dp[v] > (dp[u] + t[v]) ? dp[v] : (dp[u] + t[v]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = ans > dp[i] ? ans : dp[i];
    
    std :: printf("%d\n", ans);
    return 0;
}