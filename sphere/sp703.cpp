/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-09 04:32:07 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-09 04:53:57
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxl = 205;
const int maxn = 1005;

int c[maxl][maxl];
int p[maxn];
int f[maxn][maxl][maxl];

int main() {
    int T = read();
    while (T--) {
        int l = read(), n = read();
        std :: memset(f, 0x3f, sizeof(f));
        for (int i = 1; i <= l; ++i)
            for (int j = 1; j <= l; ++j)
                c[i][j] = read();
        for (int i = 1; i <= n; ++i)
            p[i] = read();
        
        p[0] = 1;
        f[0][2][3] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int x = 1; x <= l; ++x) {
                for (int y = 1; y <= l; ++y) {
                    int z = p[i], t = p[i + 1];
                    int fn = f[i][x][y];
                    if (x == y || y == z || x == z)
                        continue;
                    if (x != t && y != t)
                        gmi(f[i + 1][x][y], fn + c[z][t]);
                    if (x != t && z != t)
                        gmi(f[i + 1][x][z], fn + c[y][t]);
                    if (y != t && z != t)
                        gmi(f[i + 1][y][z], fn + c[x][t]);
                }
            }
        }

        int ans = INT_MAX;
        for (int x = 1; x <= l; ++x)
            for (int y = 1; y <= l; ++y)
                if (x != y && x != p[n] && y != p[n])
                    gmi(ans, f[n][x][y]);
        
        printf("%d\n", ans);
    }
    return 0;
}