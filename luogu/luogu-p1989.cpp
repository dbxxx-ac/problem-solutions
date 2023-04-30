/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 13:51:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 13:56:20
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

const int maxn = (int)1e5 + 5;
const int maxm = (int)2e5 + 5;

int d[maxn], us[maxm], vs[maxm];
std :: vector <int> G[maxn];

int t[maxn];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        us[i] = u;
        vs[i] = v;
        ++d[u];
        ++d[v];
    }

    for (int i = 1; i <= m; ++i) {
        int u = us[i], v = vs[i];
        if (d[u] > d[v])
            std :: swap(u, v);
        else if (d[u] == d[v] && u > v)
            std :: swap(u, v);
        G[u].push_back(v);
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v : G[u])
            t[v] = u;
        for (int v : G[u])
            for (int w : G[v])
                if (t[w] == u)   
                    ++ans;
    }
    
    printf("%d\n", ans);
    return 0;
}