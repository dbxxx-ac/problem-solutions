/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-02 14:21:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-02 14:45:48
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

inline bool chkmin(int &a, int b) {
    return b < a ? a = b, true : false;
}


const int maxn = 205;
const int maxinf = 0x3f3f3f3f;

int dis[maxn][maxn];
int a[maxn];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();

    std :: memset(dis, 0x3f, sizeof(dis));

    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    
    for (int i = 1; i <= m; ++i) {
        int u = read() + 1, v = read() + 1, w = read();
        dis[u][v] = dis[v][u] = w;
    }

    for (int q = read(), k = 1; q; --q) {
        int x = read() + 1, y = read() + 1, t = read();
        if (a[x] > t || a[y] > t) {
            puts("-1");
            continue;
        }
        for (; k <= n && a[k] <= t; ++k) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    chkmin(dis[i][j], dis[i][k] + dis[k][j]);
        }

        printf("%d\n", dis[x][y] >= maxinf ? -1: dis[x][y]);
    }
    return 0;
}