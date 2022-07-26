/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-05 09:20:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-06 15:01:20
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

const int maxn = 10005;
bool valid[maxn], link_end[maxn];

int dis[maxn];

std :: vector <int> side[maxn];
std :: vector <int> rev_side[maxn];

int main() {
    int n, m;
    std :: scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        std :: scanf("%d%d", &u, &v);
        side[u].push_back(v);
        rev_side[v].push_back(u);
    }

    int s, t;
    std :: scanf("%d%d", &s, &t);
    link_end[t] = true;
    std :: queue <int> q;

    q.push(t);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = rev_side[now].size() - 1; i >= 0; --i) {
            int v = rev_side[now][i];
            if (!link_end[v]) {
                q.push(v);
                link_end[v] = true;
            }
        }
    }

    if (!link_end[s]) {
        std :: printf("-1\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i)
        if (link_end[i]) {
            valid[i] = true;
            for (int j = side[i].size() - 1; j >= 0; --j) {
                int v = side[i][j];
                if (!link_end[v]) {
                    valid[i] = false;
                    break;
                }
            }
        }

    if (!valid[s]) {
        std :: printf("-1\n");
        return 0;
    }

    dis[s] = 1;
    while (!q.empty()) 
        q.pop();
    q.push(s);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == t) {
            std :: printf("%d\n", dis[t] - 1);
            return 0;
        }

        for (int i = side[now].size() - 1; i >= 0; --i) {
            int v = side[now][i];
            if (valid[v] && !dis[v]) {
                dis[v] = dis[now] + 1;
                q.push(v);
            }
        }
    }

    std :: printf("-1\n");
    return 0;
}