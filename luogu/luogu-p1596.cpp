/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-08 00:45:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-08 00:50:45
 */
#include <iostream>
#include <cstdio>

const int dx[] = {0, 1, 1, 1, -1, -1, -1, 0, 0};
const int dy[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

int n, m;

const int maxn = 105;
const int maxm = 105;

char a[maxn][maxm];

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 'W';
}

void dfs(int x, int y) {
    a[x][y] = '.';
    for (int i = 1; i <= 8; ++i) {
        int nxtx = x + dx[i];
        int nxty = y + dy[i];
        if (valid(nxtx, nxty)) {
            dfs(nxtx, nxty);
        }
    }
}

int main() {
    std :: cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std :: cin >> a[i][j];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 'W') {
                ++ans;
                dfs(i, j);
            }

    std :: cout << ans << std :: endl;
    return 0;
}