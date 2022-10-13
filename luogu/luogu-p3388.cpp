/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-03 11:27:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 11:50:43
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

const int maxn = (int)2e4 + 5;

std :: vector <int> G[maxn];

int dfn[maxn], low[maxn], times = 0;
bool isc[maxn];

inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++times;

    int ch = 0;

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            gmi(low[u], low[v]);
            if (low[v] >= dfn[u])
                isc[u] = true;
            ++ch;
        } else if (v != fa)
            gmi(low[u], dfn[v]);
    }

    if (fa == 0 && ch == 1)
        isc[u] = false;
}

int main() {
    int n = read(), m = read();
    while (m--) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u, 0);
    
    int tot = 0;

    for (int u = 1; u <= n; ++u)
        if (isc[u])
            ++tot;
    
    printf("%d\n", tot);
    for (int u = 1; u <= n; ++u)
        if (isc[u])
            printf("%d ", u);
    
    return 0;
}