/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-05 03:23:24 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-05 03:37:05
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = (int)5e5 + 5;
typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];
std :: vector <int> ecc[maxn];
int ent = 0;

std :: stack <int> s;
int dfn[maxn], low[maxn], times = 0;
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

inline void tarjan(int u, int ls) {
    dfn[u] = low[u] = ++times;
    s.push(u);

    for (pii e : G[u]) {
        int v = e.first, id = e.second;
        if (!dfn[v]) {
            tarjan(v, id);
            gmi(low[u], low[v]);
        } else if (id != ls) {
            gmi(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        ++ent;
        while (!s.empty()) {
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
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
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