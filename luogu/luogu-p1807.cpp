/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-25 21:24:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-26 09:01:11
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

const int maxn = 1505;
const int maxm = 50005;

struct edge {
    int u, v, dis;
};

int n, m;
std :: vector <edge> G[maxn];
int ind[maxn], dis[maxn];
bool flag[maxn];

void topsort() {
    flag[1] = true;
    std :: queue <int> q;
    for (int i = 1; i <= n; ++i)
        if (ind[i] == 0)
            q.push(i);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].v;
            --ind[v];
            if (flag[u]) {
                if (dis[v] < dis[u] + G[u][i].dis)
                    dis[v] = dis[u] + G[u][i].dis;
                flag[v] = true;
            }

            if (ind[v] == 0)
                q.push(v);
        }
    }
}

int main() {
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        edge now;
        std :: scanf("%d %d %d", &now.u, &now.v, &now.dis);
        G[now.u].push_back(now);
        ++ind[now.v];
    }

    dis[n] = -1;
    topsort();
    std :: printf("%d\n", dis[n]);
    return 0;
}