/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-20 15:21:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-07 11:07:11
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>

const int inf = INT_MAX;

struct node {
    int x, y, t;
};

const int maxn = 305;
const int dx[] = {0, 1, -1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};

int T[maxn][maxn];

bool valid(int x, int y, int t) {
    return x >= 0 && y >= 0 && T[x][y] > t;
}

int bfs() {
    std :: queue <node> q;
    node now;
    now.x = now.y = now.t = 0;
    q.push(now);

    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (int i = 1; i <= 4; ++i) {
            int nxtx = now.x + dx[i];
            int nxty = now.y + dy[i];
            int nxtt = now.t + 1;

            if (valid(nxtx, nxty, nxtt)) {
                node nxt;
                nxt.x = nxtx; nxt.y = nxty; nxt.t = nxtt;
                q.push(nxt);
                if (T[nxtx][nxty] == inf) return nxtt;
                else T[nxtx][nxty] = -1;
            }
        }
    }

    return -1;
}

int main() {
    int m;
    std :: scanf("%d", &m);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            T[i][j] = inf;
            
    while (m--) {
        int x, y, t;
        std :: scanf("%d %d %d", &x, &y, &t);
        if (t < T[x][y]) T[x][y] = t;
        for (int i = 1; i <= 4; i++)
            if (valid(x + dx[i], y + dy[i], t))
                T[x + dx[i]][y + dy[i]] = t;
    }

    std :: printf("%d\n", bfs());
    return 0;
}
