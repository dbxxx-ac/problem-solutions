/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-27 08:11:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-27 08:29:23
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = (int)5e5 + 5;

std :: vector <int> G[maxn];
std :: vector <int> T[maxn << 1];
std :: stack <int> s;

int dfn[maxn], low[maxn], times = 0, p = 0;

inline void dda_edge(int u, int v) {
    T[u].push_back(v);
    T[v].push_back(u);
}

int n;
void tarjan(int u) {
    if (!G[u].size()) {
        ++p;
        return dda_edge(u, n + p);
    }

    dfn[u] = low[u] = ++times;
    s.push(u);

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            gmi(low[u], low[v]);
            if (low[v] == dfn[u]) {
                ++p;
                dda_edge(u, n + p);
                for (; ;) {
                    int x = s.top();
                    s.pop();
                    dda_edge(x, n + p);
                    if (x == v)
                        break;
                }
            }
        } else
            gmi(low[u], dfn[v]);
    }
}

int main() {
    n = read();
    int m = read();
    while (m--) {
        int u = read(), v = read();
        if (u == v)
            continue;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u);

    printf("%d\n", p);
    for (int i = 1; i <= p; ++i) {
        int u = n + i;
        printf("%d ", (int)T[u].size());
        for (int v : T[u])
            printf("%d ", v);
        puts("");
    }

    return 0;
}