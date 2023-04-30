/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-27 08:49:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-27 08:59:12
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

typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int low[maxn], dfn[maxn], times = 0;
std :: stack <int> s;

int ent = 0;
std :: vector <int> ecc[maxn];

void tarjan(int u, int ls) {
    low[u] = dfn[u] = ++times;
    s.push(u);
    
    for (pii e : G[u]) {
        int v = e.first, id = e.second;
        if (id == ls)
            continue;
        if (!dfn[v]) {
            tarjan(v, id);
            gmi(low[u], low[v]);
        } else
            gmi(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++ent;
        for (; ;) {
            int x = s.top();
            s.pop();
            ecc[ent].push_back(x);
            if (x == u)
                break;
        }
    }
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u, 0);
    
    printf("%d\n", ent);
    for (int i = 1; i <= ent; ++i) {
        printf("%d ", (int)ecc[i].size());
        for (int u : ecc[i])
            printf("%d ", u);
        puts("");
    }

    return 0;
}