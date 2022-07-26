/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-13 01:19:56 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-13 01:36:09
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 1e6 + 5;
const int maxm = 2e6 + 5;
const int mod = 1e5 + 3;

struct edge {
    int to, nxt;
}e[maxm];
int ecnt = 0;
int head[maxn];
inline void add_edge(int u, int v) {
    e[++ecnt].to = v;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
}

bool vis[maxn];
int d[maxn], ans[maxn];

std :: queue <int> q;
void bfs() {
    q.push(1);
    d[1] = ans[1] = 1;
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (!vis[v]) {
                vis[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
            if (d[v] == d[u] + 1) {
                ans[v] += ans[u];
                ans[v] %= mod;
            }
        }
    }
}

int main() {
    int n = read(), m = read();
    while (m--) {
        int u = read(), v = read();
        if (u == v)
            continue;
        add_edge(u, v);
        add_edge(v, u);
    }
    bfs();
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}