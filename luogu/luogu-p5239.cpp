/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-19 23:56:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-20 00:08:02
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = 1005;
const int maxm = 1005;
const int mod = 19260817;

int C[maxn][maxm];

signed main() {
    for (int i = 0; i <= 1000; ++i)
        C[i][0] = C[i][i] = 1;
    
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    
    for (int i = 1; i <= 1000; ++i)
        for (int j = 2; j <= 1000; ++j)
            (C[i][j] += C[i][j - 1]) %= mod;
    
    for (int i = 2; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j)
            (C[i][j] += C[i - 1][j]) %= mod;

    // for (int i = 1; i <= 4; ++i, puts(""))
    //     for (int j = 1; j <= 4; ++j, putchar(' '))
    //         printf("%d", C[i][j]);
    
    int q = read();
    while (q--) {
        int n = read(), m = read();
        printf("%lld\n", C[m][n]);
    }

    return 0;
}