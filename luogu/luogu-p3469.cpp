/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-13 00:45:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-13 01:38:31
 */
#include <bits/stdc++.h>
#define int long long

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

const int maxn = (int)1e5 + 5;

std :: vector <int> G[maxn];

int siz[maxn], low[maxn], dfn[maxn], ans[maxn], times;

int n;

inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

inline void tarjan(int u) {
    dfn[u] = low[u] = ++times;
    siz[u] = 1;
    
    ans[u] = n - 1; // 第一种连通块的贡献

    int tot = n - 1; // 第三种连通块的大小，为 n-第一种连通块的大小-第二种的
    // 这里先把第一种的减去（就是1），一会还会减掉第二种的

    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            siz[u] += siz[v];
            gmi(low[u], low[v]);
            if (low[v] == dfn[u]) {
                ans[u] += siz[v] * (n - siz[v]); // 第二种连通块
                tot -= siz[v]; // 第三种连通块大小减去第二种的
            }
        } else
            gmi(low[u], dfn[v]);
    }

    ans[u] += tot * (n - tot); // 第三种连通块
}

signed main() {
    n = read();
    int m = read();
    while (m--) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }

    tarjan(1);

    for (int u = 1; u <= n; ++u)
        printf("%lld\n", ans[u]);
    
    return 0;
}