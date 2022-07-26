/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-16 17:03:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-16 17:18:28
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 355;
const int maxc = 43;

int a[maxn];
int f[maxc][maxc][maxc][maxc];
int cnt[6];

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    while (m--) {
        int x = read();
        ++cnt[x];
    }

    f[0][0][0][0] = a[1];
    for (int i = 0; i <= cnt[1]; ++i)
        for (int j = 0; j <= cnt[2]; ++j)
            for (int k = 0; k <= cnt[3]; ++k)
                for (int l = 0; l <= cnt[4]; ++l) {
                    int now = 0;
                    if (i > 0)
                        now = f[i - 1][j][k][l];
                    if (j > 0)
                        now = max(now, f[i][j - 1][k][l]);
                    if (k > 0)
                        now = max(now, f[i][j][k - 1][l]);
                    if (l > 0)
                        now = max(now, f[i][j][k][l - 1]);
                    now += a[1 + i + j * 2 + k * 3 + l * 4];
                    f[i][j][k][l] = now;
                }

    printf("%d\n", f[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}