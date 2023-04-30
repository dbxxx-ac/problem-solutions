/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-27 08:33:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-27 09:20:29
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

const int maxn = 10005;
const int maxm = 1005;
const int inf = 0x3f3f3f3f;

int f[maxn][maxm];
int ds[maxn], us[maxn];
int up[maxn], dn[maxn];

int main() {
    int n = read(), m = read(), k = read();
    for (int i = 0; i < n; ++i) {
        up[i] = read();
        dn[i] = read();
    }
    for (int i = 0; i <= n; ++i) {
        ds[i] = 1;
        us[i] = m;
    }
    while (k--) {
        int p = read(), l = read(), h = read();
        ds[p] = l + 1;
        us[p] = h - 1;
    }

    std :: memset(f, 0x3f, sizeof(f));
    for (int i = ds[0]; i <= us[0]; ++i)
        f[0][i] = 0;
    
    int ans = inf, cur = (us[0] == m) ? 0 : 1;
    for (int i = 1; i <= n; ++i) {
        ans = inf;
        for (int j = up[i - 1] + 1; j <= m; ++j) {
            int lst = j - up[i - 1];
            if (lst >= ds[i - 1] && lst <= us[i - 1])
                gmi(f[i][j], f[i - 1][j - up[i - 1]] + 1);
            gmi(f[i][j], f[i][j - up[i - 1]] + 1);
            if (j >= ds[i] && j <= us[i])
                gmi(ans, f[i][j]);
        }
        if (us[i] == m) {
            for (int j = m; j > m - up[i - 1]; --j) {
                if (j >= ds[i - 1] && j <= us[i - 1])
                    gmi(f[i][m], f[i - 1][j] + 1);
                gmi(f[i][m], f[i][j] + 1);
                gmi(ans, f[i][m]);
            }
        }
        for (int j = ds[i]; j <= std :: min(us[i], m - dn[i - 1]); ++j) {
            if (j + dn[i - 1] >= ds[i - 1] && j + dn[i - 1] <= us[i - 1])
                gmi(f[i][j], f[i - 1][j + dn[i - 1]]);
            gmi(ans, f[i][j]);
        }
        if (ans == inf) {
            puts("0");
            printf("%d\n", cur);
            return 0;
        }
        cur += ((us[i] == m) ? 0 : 1);
    }

    puts("1");
    printf("%d\n", ans);
    return 0;
}