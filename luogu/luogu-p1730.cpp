/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-02-10 11:35:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-10 12:22:01
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

// 枚举长度 floyd 即可 DAG 不会有路径超过 n-1

const int maxn = 55;
int dis[maxn][maxn][maxn];

int main() {
    std :: memset(dis, 0x3f, sizeof(dis));
    int n = read(), m = read();
    while (m--) {
        int u = read(), v = read();
        gmi(dis[u][v][1], read());
    }

    for (int l = 2; l <= n; ++l)
    for (int k = 1; k <= n; ++k)
    for (int u = 1; u <= n; ++u)
    for (int v = 1; v <= n; ++v)
    gmi(dis[u][v][l], 
    dis[u][k][l - 1] + dis[k][v][1]);

    // std :: cout << dis[2][3][2] << std :: endl;
    
    int q = read();
    while (q--) {
        int u = read(), v = read();
        double ans = 1145141919;
        for (int l = 1; l <= n; ++l) {
            if (dis[u][v][l] == 0x3f3f3f3f)
                continue;
            ans = std :: min(
                ans, dis[u][v][l] * 1.0 / l
            );
        }
        if (ans == 1145141919)
            puts("OMG!");
        else
            printf("%.3lf\n", ans);
    }

    return 0;
}