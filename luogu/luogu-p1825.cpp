/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-08 08:29:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-08 09:53:39
 */
#include <iostream>
#include <cstdio>
#include <queue>

struct step {
    int x;
    int y;
    int t;
};

const int maxn = 305;
const int maxm = 305;
const int dx[] = {0, 1, -1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};

char a[maxn][maxm];

int n, m;

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#';
}

void teleport(int &x, int &y) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[x][y] == a[i][j] && (x != i || y != j)) {
                x = i;
                y = j;
                return ;
            }
}

int bfs(int startx, int starty) {
    std :: queue <step> q;
    step now;
    now.x = startx; now.y = starty; now.t = 0;
    a[startx][starty] = '#';
    q.push(now);
    
    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (int i = 1; i <= 4; ++i) {
            int nxtx = now.x + dx[i];
            int nxty = now.y + dy[i];

            if (valid(nxtx, nxty)) {                
                step nxt;
                nxt.x = nxtx;
                nxt.y = nxty;
                nxt.t = now.t + 1;

                if (a[nxtx][nxty] == '=') return nxt.t;
                if (a[nxt.x][nxt.y] >= 'A' && a[nxt.x][nxt.y] <= 'Z') {
                    teleport(nxt.x, nxt.y);
                }
                else a[nxtx][nxty] = '#';
                q.push(nxt);
            }
        }
    }

    return -1;
}

int main() {
    int startx, starty;
    std :: cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            std :: cin >> a[i][j];
            if (a[i][j] == '@') {
                startx = i;
                starty = j;
            }
        }

    std :: cout << bfs(startx, starty) << std :: endl;
    return 0;
}