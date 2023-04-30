/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-17 02:13:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-17 02:20:25
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

const int mod = (int)1e9 + 7, in2 = (int)5e8 + 4;
const int maxn = 2005, maxm = 2005;

int f[maxn][maxm];

signed main() {
    for (int i = 1; i <= 2000; ++i)
        f[i][i] = i;
    
    for (int i = 2; i <= 2000; ++i)
        for (int j = 1; j < i; ++j)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod * in2 % mod;
    
    int q = read();
    while (q--) {
        int n = read(), m = read(), k = read();
        printf("%lld\n", f[n][m] * k % mod);
    }
    return 0;
}