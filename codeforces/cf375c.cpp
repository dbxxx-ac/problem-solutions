/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-12 16:58:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-15 18:31:51
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

inline int max(int a, int b) {
    return a > b ? a : b;
}

const int maxn = 25;
const int maxm = 25;
const int maxk = 10;
const int inf = 0x3f3f3f3f / 8;

char a[maxn][maxm];
int v[maxk];
int px[maxk], py[maxk];
int g[1 << maxk];
int f[maxn][maxm][1 << maxk];

int n, m, k;

struct node {
    int x, y, s;
};

std :: queue <node> q;

inline bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && (a[x][y] == '.' || a[x][y] == 'S');
}

inline int chg(int x, int y, int id, bool up) {
    if (py[id] > y)
        return 0;
    if (up)
        return (x == px[id]) ? 1 : 0;
    else
        return (x + 1 == px[id]) ? 1 : 0;
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

inline int bfs(int sx, int sy) {
    int ans = 0;
    q.push((node){sx, sy, 0});
    std :: memset(f, -1, sizeof(f));
    f[sx][sy][0] = 0;
    
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, s = q.front().s;
        q.pop();
        if (x == sx && y == sy)
            ans = max(ans, g[s] - f[x][y][s]);
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i], ns = s;
            if (!check(nx, ny))
                continue;
            if (dx[i] != 0)
                for (int j = 0; j < k; ++j)
                    ns ^= (chg(x, y, j + 1, dx[i] < 0) << j);
            
            if (f[nx][ny][ns] != -1)
                continue;
            f[nx][ny][ns] = f[x][y][s] + 1;
            q.push((node){nx, ny, ns});
        }
    }
    return ans;
}

int main() {
    n = read();
    m = read();
    int sx = 1, sy = 1; // 苹果园坐标
    
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; ++j) {
            char c = a[i][j];
            if (c == 'S') {
                sx = i;
                sy = j;
            } else if (isdigit(c)) {
                px[c ^ 48] = i;
                py[c ^ 48] = j;
                ++k;
            }
        }
    }

    for (int i = 1; i <= k; ++i)
        v[i] = read();
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c = a[i][j];
            if (c == 'B') {
                px[++k] = i;
                py[k] = j;
                v[k] = -inf;
            }
        }
    }
    
    for (int i = 0; i < (1 << k); ++i)
        for (int j = 0; j < k; ++j)
            if (i & (1 << j))
                g[i] += v[j + 1];
    
    printf("%d\n", bfs(sx, sy));
    return 0;
}
