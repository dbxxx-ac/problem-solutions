/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-22 20:46:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-22 21:55:05
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = 13, maxm = 7;
const int maxs = (1 << 12) + 5, maxt = (1 << 5) + 5;

double f[maxs][maxt][maxn + maxm];

double px[maxn + maxm], py[maxn + maxm];
double dis[maxn + maxm][maxn + maxm];

inline int popcnt(int x) {
    int ans = 0;
    for (; x; x >>= 1)
        if (x & 1)
            ++ans;
    return ans;
}

inline bool gmi(double &a, double b) {
    return b < a ? a = b, true : false;
}

signed main() {
    int n = read(), m = read();

    for (int i = 0; i < n + m; ++i) {
        px[i] = (double)read();
        py[i] = (double)read();
        for (int j = 0; j < i; ++j) {
            dis[i][j] = dis[j][i] = 
            hypot(px[i] - px[j], py[i] - py[j]);
        }
    }

    std :: memset(f, 0x42, sizeof(f));
    
    for (int u = 0; u < n; ++u)
        f[1 << u][0][u] = hypot(px[u], py[u]);
    
    for (int u = 0; u < m; ++u)
        f[0][1 << u][u + n] = hypot(px[u + n], py[u + n]);
    
    for (int S = 0; S < (1 << n); ++S) {
        for (int T = 0; T < (1 << m); ++T) {
            for (int u = 0; u < n + m; ++u) {
                if (u >= n) {
                    if ((T & (1 << (u - n))) == 0)
                        continue;
                } else if ((S & (1 << u)) == 0)
                    continue;

                double now = f[S][T][u];
                double sp = (1 << (popcnt(T)));
                // std :: cout << popcnt(T) << std :: endl;
                for (int v = 0; v < n; ++v) {
                    if (S & (1 << v))
                        continue;
                    gmi(f[S | (1 << v)][T][v], 
                    now + dis[u][v] / (sp * 1.0));
                }
                for (int v = 0; v < m; ++v) {
                    if (T & (1 << v))
                        continue;
                    gmi(f[S][T | (1 << v)][v + n], 
                    now + dis[u][v + n] / (sp * 1.0));
                }
            }
        }
    }

    double ans = DBL_MAX;
    int S = (1 << n) - 1;
    for (int T = 0; T < (1 << m); ++T)
        for (int u = 0; u < n + m; ++u)
            gmi(ans, f[S][T][u] + hypot(px[u], py[u]) / (1 << popcnt(T)));

    printf("%.8lf\n", ans);
    return 0;
}