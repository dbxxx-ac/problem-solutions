/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-19 23:24:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-20 00:25:15
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

const int maxn = 10005;
const int maxm = 11;
const int maxk = 105;
const int inf = 0x3f3f3f3f;

int a[maxn], b[maxk], p[maxm << 1], tot = 0;
int n, m, k;

int dis[maxm << 1][maxn];
int f[(1 << (maxm << 1))], s[(1 << (maxm << 1))];

void spfa() {
    for (int i = 0; i < tot; ++i) {
        std :: memset(dis[i], 0x3f, sizeof(dis[i]));

        dis[i][p[i]] = 0;
        std :: queue <int> q;
        q.push(p[i]);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j = 1; j <= k; ++j) {
                int v = u - b[j];
                if (v >= 0 && dis[i][u] + 1 < dis[i][v]) {
                    dis[i][v] = dis[i][u] + 1;
                    q.push(v);
                }
                v = u + b[j];
                if (v <= n && dis[i][u] + 1 < dis[i][v]) {
                    dis[i][v] = dis[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    n = read();
    m = read();
    k = read();
    for (int i = 1; i <= m; ++i)
        a[read()] = 1;
    
    for (int i = 1; i <= k; ++i)
        b[i] = read();
    
    for (int i = 0; i <= n; ++i)
        if (a[i] ^= a[i + 1])
            p[tot++] = i;
    
    spfa();
    
    std :: memset(f, 0x3f, sizeof(f));
    f[0] = 0;

    for (int i = 0; i < tot; ++i)
        s[1 << i] = i;
    
    const int all = (1 << tot) - 1;
    for (int i = 1; i <= all; ++i) {
        int t = i & (-i), u = s[t];
        // printf("%d\n", t);
        for (int v = u + 1; v < tot; ++v) {
            if (i & (1 << v)) {
                // printf("%d %d\n", u, v);
                f[i] = min(f[i], f[i ^ t ^ (1 << v)] + dis[u][p[v]]);
            }
        }
    }
    
    // printf("%d\n", dis[0][3]);
    printf("%d\n", f[all] >= inf ? -1 : f[all]);
    return 0;
}


/*
10 8 2
1 2 3 5 6 7 8 9
3 5

1 0 0 1 1 0 0 0 0 1 0
*/