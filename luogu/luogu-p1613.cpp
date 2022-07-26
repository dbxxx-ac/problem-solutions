/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-04 13:55:04 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-04 14:09:23
 */
#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 55;
const int maxlogdis = 65;
inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline int min(int a, int b) {
    return a < b ? a : b;
}

int dis[maxn][maxn];
bool dir[maxn][maxn][maxlogdis];

int main() {
    std :: memset(dir, 0, sizeof(dir));
    std :: memset(dis, maxn, sizeof(dis));
    
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        dis[u][v] = 1;
        dir[u][v][0] = true;
    }

    for (int k = 1; k < maxlogdis; ++k)
        for (int u = 1; u <= n; ++u)
            for (int i = 1; i <= n; ++i)
                for (int v = 1; v <= n; ++v)
                    if (dir[u][i][k - 1] && dir[i][v][k - 1]) {
                        dir[u][v][k] = true;
                        dis[u][v] = 1;
                    }
    
    for (int i = 1; i <= n; ++i)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                dis[u][v] = min(dis[u][v], dis[u][i] + dis[i][v]);
    
    std :: printf("%d\n", dis[1][n]);
    return 0;
}