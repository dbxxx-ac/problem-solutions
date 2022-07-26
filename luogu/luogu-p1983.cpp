/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 09:14:56 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 13:58:43
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

const int maxn = 1005;
const int maxm = 1005;

std :: vector <int> G[maxn];
int ind[maxn];
bool vis[maxn][maxn];

int n, m;
int topsort() {
    std :: queue <std :: pair <int, int> > q;
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        if (ind[i] == 0)
            q.push(std :: make_pair(i, 1));
            
    while (!q.empty()) {
        int u = q.front().first, level = q.front().second;
        q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            --ind[v];
            if (ind[v] == 0) {
                q.push(std :: make_pair(v, level + 1));
                ans = ans > level + 1 ? ans : level + 1;
            }
        }
    }

    return ans;
}

int main() {
    std :: scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        int s;
        std :: scanf("%d", &s);
        int stop[maxn];
        bool is_stop[maxn] = {false};
        for (int j = 1; j <= s; ++j) {
            std :: scanf("%d", &stop[j]);
            is_stop[stop[j]] = true;
        }

        for (int j = stop[1]; j <= stop[s]; ++j) {
            if (!is_stop[j]) {
                for (int k = 1; k <= s; ++k) {
                    if (!vis[j][stop[k]]) {
                        ++ind[stop[k]];
                        G[j].push_back(stop[k]);
                        vis[j][stop[k]] = true;
                    }
                }
            }
        }
    }

    std :: printf("%d\n", topsort());
    return 0;
}