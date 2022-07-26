/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-26 21:03:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-30 18:21:28
 */
#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 1505;
const int dx[] = {0, 1, -1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};

char a[maxn][maxn];
bool vis[maxn][maxn];
int visu[maxn][maxn][2];
bool fnd;

int n, m;

void dfs(int x, int y, int ux, int uy) {
    if (fnd) return ;
    if (vis[x][y] && (visu[x][y][0] != ux || visu[x][y][1] != uy)) {
        fnd = true;
        return ;
    }

    vis[x][y] = true;
    visu[x][y][0] = ux;
    visu[x][y][1] = uy;

    for (int i = 1; i <= 4; ++i) {
        int nxtx = (x + dx[i] + n - 1) % n + 1;
        int nxty = (y + dy[i] + m - 1) % m + 1;
        int nxtux = ux + dx[i];
        int nxtuy = uy + dy[i];

        if (a[nxtx][nxty] != '#')
            if (!vis[nxtx][nxty] || visu[nxtx][nxty][0] != nxtux || visu[nxtx][nxty][1] != nxtuy)
                dfs(nxtx, nxty, nxtux, nxtuy);
    }
}

int main() {
    while (~std :: scanf("%d %d", &n, &m)) {
        fnd = false;
        int sx, sy;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                vis[i][j] = false;

        for (int i = 1; i <= n; ++i) {
            std :: scanf("%s", a[i] + 1);
            for (int j = 1; j <= m; ++j)
                if (a[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
        }

        dfs(sx, sy, sx, sy);
        std :: printf("%s\n", fnd ? "Yes" : "No");
    }

    return 0;
}