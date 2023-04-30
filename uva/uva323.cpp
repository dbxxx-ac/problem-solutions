/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-12 04:14:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-12 05:24:51
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = 205;
const int maxm = 25;
const int maxv = (maxm * 20) << 1;
const int par = maxm * 20;

int f[maxm][maxv];
int d[maxn], p[maxn];
int pre[maxn][maxm][maxv];

void pr(int i, int j, int k) {
    if (j == 0)
        return ;
    int id = pre[i][j][k + par];
    pr(id - 1, j - 1, k - d[id] + p[id]);
    printf(" %d", id);
}

int main() {
    for (int cas = 1, n = read(), m = read(); n; ++cas, n = read(), m = read()) {
        std :: memset(f, 0xc0, sizeof(f));
        f[0][par] = 0;
        for (int i = 1; i <= n; ++i) {
            p[i] = read();
            d[i] = read();
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = m; j; --j)
                for (int k = -400; k <= 400; ++k)
                    if (gmx(f[j][k + par], 
                            f[j - 1][k - d[i] + p[i] + par] 
                            + d[i] + p[i]))
                        pre[i][j][k + par] = i;
                    else
                        pre[i][j][k + par] = pre[i - 1][j][k + par];
        }
        
        for (int dif = 0; dif <= 400; ++dif) {
            int ps = f[m][par + dif], ng = f[m][par - dif];
            if (ps < 0 && ng < 0)
                continue;
            int k = dif;
            if (ps < 0 || ng > ps)
                k = -dif;
            
            printf("Jury #%d\n", cas);
            printf("Best jury has value %d for prosecution and value %d for defence:\n", (f[m][k + par] - k) >> 1, (f[m][k + par] + k) >> 1);
            pr(n, m, k);
            puts("");
            puts("");
            break;
        }
    }

    return 0;
}