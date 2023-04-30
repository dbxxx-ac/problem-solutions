/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-19 15:36:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-19 17:59:46
 */
#include <bits/stdc++.h>
#define int long long
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
typedef std :: pair <int, int> pii;

const int maxn = 1005;
const int maxm = 1005;

int n, m;
int a[maxn][maxm];
int dis[3][maxn][maxm];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

inline void dijkstra(int id, int sx, int sy) {
    std :: priority_queue <std :: pair <int, pii> > q;
    std :: memset(dis[id], 0x3f, sizeof(dis[id]));
    dis[id][sx][sy] = a[sx][sy];
    q.push({-a[sx][sy], std :: make_pair(sx, sy)});

    while (!q.empty()) {
        int d = q.top().first, x = q.top().second.first, y = q.top().second.second;
        q.pop();
        if (d + dis[id][x][y])
            continue;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (dis[id][nx][ny] > dis[id][x][y] + a[nx][ny]) {
                dis[id][nx][ny] = dis[id][x][y] + a[nx][ny];
                q.push({-dis[id][nx][ny], std :: make_pair(nx, ny)});
            } 
        }
    }
}

signed main() {
    n = read(), m = read();
    int A = read(), B = read(), C = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = read();
    dijkstra(0, 1, A);
    dijkstra(1, n, B);
    dijkstra(2, n, C);

    int ans = dis[0][0][0];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            gmi(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - 2 * a[i][j]);
    printf("%lld\n", ans);
    return 0;
}