/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-01 01:57:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-01 02:29:34
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


const int maxn = 30;
unsigned f[maxn][maxn][maxn][maxn][maxn];
int a[7];

int main() {
    int n = 0;

    while ((n = read()) && n) {
        std :: memset(f, 0, sizeof(f));
        std :: memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i)
            a[i] = read();

        f[0][0][0][0][0] = 1;
        for (int x1 = 0; x1 <= a[1]; ++x1)
        for (int x2 = 0; x2 <= a[2]; ++x2)
        for (int x3 = 0; x3 <= a[3]; ++x3)
        for (int x4 = 0; x4 <= a[4]; ++x4)
        for (int x5 = 0; x5 <= a[5]; ++x5) {
            int now = f[x1][x2][x3][x4][x5];
            if (x1 < a[1])
                f[x1 + 1][x2][x3][x4][x5] += now;
            if (x2 < a[2] && x2 < x1)
                f[x1][x2 + 1][x3][x4][x5] += now;
            if (x3 < a[3] && x3 < x2)
                f[x1][x2][x3 + 1][x4][x5] += now;
            if (x4 < a[4] && x4 < x3)
                f[x1][x2][x3][x4 + 1][x5] += now;
            if (x5 < a[5] && x5 < x4)
                f[x1][x2][x3][x4][x5 + 1] += now;
        }

        printf("%u\n", f[a[1]][a[2]][a[3]][a[4]][a[5]]);
    }

    return 0;
}