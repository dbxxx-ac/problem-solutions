/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-27 08:32:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-27 08:37:29
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

const int maxn = (int)2e4 + 5;

std :: vector <int> G[maxn];
int deg[maxn];
int dfn[maxn], low[maxn], times = 0;
std :: stack <int> s;

void tarjan(int u) {
    if (!G[u].size()) {
        ++deg[u];
        return ;
    }
    
    dfn[u] = low[u] = ++times;
    s.push(u);

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            gmi(low[u], low[v]);
            if (low[v] == dfn[u]) {
                ++deg[u];
                for (; ;) {
                    int x = s.top();
                    s.pop();
                    ++deg[x];
                    if (x == v)
                        break;
                }
            }
        } else
            gmi(low[u], dfn[v]);
    }
}

int main() {
    int n = read(), m = read();
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
    
    std :: vector <int> ans;

    for (int u = 1; u <= n; ++u)
        if (deg[u] > 1)
            ans.push_back(u);
    
    printf("%d\n", (int)ans.size());

    for (int u : ans)
        printf("%d ", u);
    puts("");
    return 0;
}