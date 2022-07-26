/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-05-04 00:22:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-05-04 01:18:18
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>

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

const int inf = 0x3f3f3f3f;

const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};

const int maxh = 7;
const int maxw = 7;
const int maxt = 109;
const int maxn = 25;
const int maxm = 11;

int a[maxh][maxw][maxt], dp[maxh][maxw][maxt][1 << maxm];

int h, w, T, sx, sy, n, m;

int main() {
    h = read();
    w = read();
    T = read();
    sx = read();
    sy = read();
    n = read();
    m = read();
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        int t1 = read(), t2 = read(), q = read();
        int num = -1;
        if (q)
            num = (cnt <<= 1) >> 1;
        for (int t = t1; t < t2; ++t) {
            int x = read(), y = read();
            a[x][y][t] = num;
        }
    }

    if (a[sx][sy][1] == -1) {
        puts("-1");
        return 0;
    }

    std :: memset(dp, 0x3f, sizeof(dp));
    
    int tot = (1 << m) - 1;

    dp[sx][sy][1][a[sx][sy][1]] = 0;
    
    for (int t = 2; t <= T; ++t)
        for (int x = 1; x <= w; ++x)
            for (int y = 1; y <= h; ++y) {
                int s = a[x][y][t];
                if (s == -1)
                    continue;
                for (int i = 0; i <= 4; ++i) {
                    int lstx = x + dx[i];
                    int lsty = y + dy[i];
                    if (lstx < 1 || lstx > h || lsty < 1 || lsty > w)
                        continue;
                    if (a[lstx][lsty][t - 1] == -1)
                        continue;
                    for (int k = 0; k <= tot; ++k)
                        dp[x][y][t][k | s] = std :: min(dp[x][y][t][k | s], dp[lstx][lsty][t - 1][k] + (i > 0 ? 1 : 0));
                }
            }
    
    int ans = inf;
    for (int x = 1; x <= w; ++x)
        for (int y = 1; y <= h; ++y)
            ans = std :: min(ans, dp[x][y][T][tot]);
    
    if (ans == inf)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}