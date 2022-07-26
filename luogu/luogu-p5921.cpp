/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-03 23:17:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-03 23:24:36
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

const int maxn = 1005;
const int n = 1000;

int fa[maxn], ind[maxn], oud[maxn], c[maxn];
bool exi[maxn], vis[maxn][maxn];

int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    int m = read();
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int _ = 1; _ <= m; ++_) {
        int u = read(), v = read();
        if (vis[u][v]) {
            --_;
            --m;
            continue;
        }
        vis[u][v] = true;
        ++ind[v];
        ++oud[u];
        exi[u] = exi[v] = true;
        fa[get(u)] = get(v);
    }

    for (int i = 1; i <= n; ++i)
        if (ind[i] > oud[i])
            c[get(i)] += ind[i] - oud[i];
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (exi[i] && get(i) == i)
            ans += std :: max(1, c[i]);
    printf("%d\n", ans + m);
    return 0;
}