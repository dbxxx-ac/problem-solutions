/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-18 16:36:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-18 17:02:35
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

const int maxn = (int)2e5 + 5;
typedef std :: pair <int, int> pii;
std :: vector <pii> G[maxn];

int con[2][maxn];
int siz[2][maxn];

void dfs(int u, int x, int id) {
    con[x][u] = id;
    ++siz[x][id];
    for (pii e : G[u]) {
        int v = e.first, w = e.second;
        if (w != x || con[x][v])
            continue;
        dfs(v, x, id);
    }
}


signed main() {
    int n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    for (int u = 1; u <= n; ++u) {
        if (!con[0][u])
            dfs(u, 0, u);
        if (!con[1][u])
            dfs(u, 1, u);
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u)
        ans += siz[0][con[0][u]] * siz[1][con[1][u]] - 1;
    
    printf("%lld\n", ans);
    return 0;
}