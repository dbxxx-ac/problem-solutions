/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-23 20:42:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-23 20:55:02
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

const int maxn = 105;
int dis[maxn][maxn], a[maxn][maxn];

int main() {
    int n = read(), m = read();
    std :: memset(a, 0x2a, sizeof(a));
    std :: memset(dis, 0x2a, sizeof(dis));
    while (m--) {
        int u = read(), v = read(), w = read();
        gmi(dis[u][v], w);
        gmi(dis[v][u], w);
        gmi(a[u][v], w);
        gmi(a[v][u], w);
    }

    int ans = 0x2a2a2a2a;

    for (int k = 1; k <= n; ++k) {
        for (int u = 1; u < k; ++u)
            for (int v = u + 1; v < k; ++v)
                gmi(ans, dis[u][v] + a[u][k] + a[v][k]);
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                gmi(dis[u][v], dis[u][k] + dis[k][v]);
    }

    if (ans == 0x2a2a2a2a) {
        puts("No solution.");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}