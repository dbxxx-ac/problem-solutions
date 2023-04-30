/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-06 00:59:09 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-06 03:02:53
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

const int maxn = 505;
const int maxm = 505;

int a[maxn], b[maxm];
int f[maxn][maxm];
int pre[maxn][maxm];

void pr(int x, int n) {
    if (x == 0)
        return ;
    pr(pre[n][x], n);
    printf("%d ", b[x]);
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    int m = read();
    for (int i = 1; i <= m; ++i)
        b[i] = read();
    
    a[0] = b[0] = -1;

    for (int i = 1; i <= n; ++i) {
        int k = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[i] != b[j]) {
                f[i][j] = f[i - 1][j];
                pre[i][j] = pre[i - 1][j];
            } else {
                f[i][j] = f[i - 1][k] + 1;
                pre[i][j] = k;
            }

            if (b[j] < a[i] && f[i - 1][j] > f[i - 1][k])
                k = j;
        }
    }

    int st = 0;
    for (int i = 1; i <= m; ++i)
        if (f[n][i] > f[n][st])
            st = i;

    printf("%d\n", f[n][st]);
    pr(st, n);
    puts("");
    return 0;
}