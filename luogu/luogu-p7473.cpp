/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-22 08:00:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-22 19:27:17
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

const int maxn = 255, maxm = 255;
int id[maxn][maxn];

std :: vector <int> G[(maxn + maxm) << 2][4];
int fall[maxn][maxn][4];
int dis[(maxn + maxm) << 2][(maxn + maxm) << 2];

int main() {
    int n = read(), m = read(), Q = read();
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        id[x][y] = -1;
    }

    for (int i = 1; i <= n; ++i)
        id[i][0] = id[0][i] = id[i][n + 1] = id[n + 1][i] = -1;
    
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (id[i][j] < 0)
                continue;
            if (id[i - 1][j] < 0 || id[i + 1][j] < 0 || id[i][j - 1] < 0 || id[i][j + 1] < 0)
                id[i][j] = ++cnt;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = id[i][j];
            if (x < 0)
                continue;
            if (id[i][j - 1] < 0)
                fall[i][j][0] = x;
            else
                fall[i][j][0] = fall[i][j - 1][0];
            
            if (id[i - 1][j] < 0)
                fall[i][j][1] = x;
            else
                fall[i][j][1] = fall[i - 1][j][1];
            
            if (x > 0) {
                G[fall[i][j][0]][0].push_back(x);
                G[fall[i][j][1]][1].push_back(x);
            }
        }
    }

    for (int i = n; i; --i) {
        for (int j = n; j; --j) {
            int x = id[i][j];
            if (x < 0)
                continue;
            if (id[i][j + 1] < 0)
                fall[i][j][2] = x;
            else
                fall[i][j][2] = fall[i][j + 1][2];
            
            if (id[i + 1][j] < 0)
                fall[i][j][3] = x;
            else
                fall[i][j][3] = fall[i + 1][j][3];
            
            if (x > 0) {
                G[fall[i][j][2]][2].push_back(x);
                G[fall[i][j][3]][3].push_back(x);
            }
        }
    }

    std :: queue <std :: pair <std :: pair <int, int>, int> > q;
    std :: memset(dis, 0x3f, sizeof(dis));
    
    const int inf = dis[0][0];
    for (int i = 1; i <= cnt; ++i) {
        q.push({{i, i}, 0});
        dis[i][i] = 0;
    }
    
    while (!q.empty()) {
        int a = q.front().first.first, b = q.front().first.second, d = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            for (int nxta : G[a][dir])
            for (int nxtb : G[b][dir])
            if (dis[nxta][nxtb] == inf) {
                dis[nxta][nxtb] = d + 1;
                q.push({{nxta, nxtb}, d + 1});
            }
        }
    }

    while (Q--) {
        int a = read(), b = read(), c = read(), d = read();
        if (a == c && b == d) {
            puts("0");
            continue;
        }

        int ans = inf;
        for (int dir = 0; dir < 4; ++dir) {
            ans = std :: min(ans, 
                dis[fall[a][b][dir]][fall[c][d][dir]] + 1
            );
        }
        printf("%d\n", (ans == inf) ? -1 : ans);
    }

    return 0;
}