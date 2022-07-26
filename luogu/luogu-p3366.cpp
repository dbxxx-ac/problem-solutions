/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-06 16:13:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-06 16:24:30
 */
#include <bits/stdc++.h>

const int maxn = 5005;
const int maxm = 200005;
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) return x;
    return ~(x - 1);
}

int fa[maxn], n, m;
struct edge {
    int u, v, w;
    const bool operator < (const edge& b) {
        return this -> w < b.w;
    } 
}e[maxm];

int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

bool unite(int x, int y) {
    int fax = find(x);
    int fay = find(y);
    if (fax == fay)
        return false;
    fa[fax] = fay;
    return true;
}

int kruskal() {
    std :: sort(e + 1, e + 1 + m);
    int ans = 0;
    for (int i = 1; i <= m; ++i)
        if (unite(e[i].u, e[i].v))
            ans += e[i].w;
    return ans;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }

    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    
    std :: printf("%d\n", kruskal());
    return 0;
}

