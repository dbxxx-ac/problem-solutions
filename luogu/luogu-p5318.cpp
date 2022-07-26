/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-16 11:35:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-16 11:48:53
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>

const int maxn = 100005;

std :: set <int> e[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = true;
    std :: printf("%d ", u);
    for (std :: set <int> :: iterator it = e[u].begin(); it != e[u].end(); ++it) {
        if (!vis[*it]) dfs(*it);
    }
}

void bfs(int u) {
    int now = u;
    std :: queue <int> q;
    q.push(now);
    std :: printf("%d ", u);
    vis[now] = true;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (std :: set <int> :: iterator it = e[now].begin(); it != e[now].end(); ++it) {
            if (!vis[*it]) {
                q.push(*it);
                std :: printf("%d ", *it);
                vis[*it] = true;
            }
        }
    }
}

int main() {
    int n, m;
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std :: scanf("%d %d", &u, &v);
        e[u].insert(v);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    putc('\n', stdout);
    bfs(1);
    return 0;
}