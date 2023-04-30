/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-30 22:49:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-30 23:15:25
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
inline int max(int a, int b) {
    return a > b ? a : b;
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
inline int min(int a, int b) {
    return a < b ? a : b;
}

const int maxn = (int)1e5 + 5;
const int maxm = (int)1e5 + 5;
const int mlgn = 25;
const int mlgm = 25;

int amx[maxn][mlgn], amn[maxn][mlgn], afx[maxn][mlgn], azn[maxn][mlgn];
int bmx[maxm][mlgm], bmn[maxm][mlgm];

// 6 个 ST 表
// amx：a 的最大值，amn：a 的最小值，afx：a 的负数最大值，azn：a 的非负数最小值。
// bmx：b 的最大值，bmn：b 的最小值。

int lg[maxn];

const int maxinf = LONG_LONG_MAX, mininf = LONG_LONG_MIN;

signed main() {
    int n = read(), m = read(), q = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        amx[i][0] = amn[i][0] = x;
        afx[i][0] = (x < 0 ? x : mininf);
        azn[i][0] = (x >= 0 ? x : maxinf);
    }

    for (int i = 1; i <= m; ++i) {
        int x = read();
        bmx[i][0] = bmn[i][0] = x;
    }

    for (int i = 2; i <= max(n, m); ++i)
        lg[i] = lg[i >> 1] + 1;

    for (int j = 1; j <= lg[n]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            int p = i + (1 << (j - 1));
            amx[i][j] = max(amx[i][j - 1], amx[p][j - 1]);
            afx[i][j] = max(afx[i][j - 1], afx[p][j - 1]);
            amn[i][j] = min(amn[i][j - 1], amn[p][j - 1]);
            azn[i][j] = min(azn[i][j - 1], azn[p][j - 1]);
        }
    }

    for (int j = 1; j <= lg[m]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
            int p = i + (1 << (j - 1));
            bmx[i][j] = max(bmx[i][j - 1], bmx[p][j - 1]);
            bmn[i][j] = min(bmn[i][j - 1], bmn[p][j - 1]);
        }
    }

    while (q--) {
        int la = read(), ra = read(), lb = read(), rb = read();
        int sa = lg[ra - la + 1], sb = lg[rb - lb + 1];
        int pa = ra - (1 << sa) + 1, pb = rb - (1 << sb) + 1;

        int amax = max(amx[la][sa], amx[pa][sa]);
        int amin = min(amn[la][sa], amn[pa][sa]);
        int afmx = max(afx[la][sa], afx[pa][sa]);
        int azmn = min(azn[la][sa], azn[pa][sa]);
        int bmax = max(bmx[lb][sb], bmx[pb][sb]);
        int bmin = min(bmn[lb][sb], bmn[pb][sb]);

        int ans = mininf;

        gmx(ans, amax * (amax >= 0 ? bmin : bmax));
        gmx(ans, amin * (amin >= 0 ? bmin : bmax));
        if (afmx != mininf)
            gmx(ans, afmx * (afmx >= 0 ? bmin : bmax));
        if (azmn != maxinf)
            gmx(ans, azmn * (azmn >= 0 ? bmin : bmax));
        printf("%lld\n", ans);
    }
    return 0;
}