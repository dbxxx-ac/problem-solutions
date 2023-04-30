/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-23 19:07:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-23 19:33:09
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

const int maxn = (int)1e5 + 5;
std :: vector <int> G[maxn];
int deg[maxn], dis[maxn];

int main() {
    int n = read(), k = n - read();
    std :: queue <int> q;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    for (int u = 1; u <= n; ++u) {
        if (deg[u] == 1) {
            q.push(u);
            dis[u] = 1;
        }
    }

    int ans = 0;

    while (!q.empty() && k) {
        int u = q.front();
        q.pop();
        ans = dis[u];
        --k;
        for (int v : G[u]) {
            --deg[v];
            if (deg[v] == 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}