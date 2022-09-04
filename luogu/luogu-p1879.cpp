/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-02 16:16:36 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-02 16:55:28
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

const int maxn = 15, maxm = 15;
const int mod = 100000000;

int g[maxn];
int f[maxn][(1 << 12) + 5];

inline bool check(int i, int s) {
    if (s & (s << 1))
        return false;
    if (s & (s >> 1))
        return false;
    return (s & g[i]) == s;
}

signed main() {
    int n = read(), m = read();
    int S = 1 << m;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            g[i] = (g[i] << 1) | read();
    
    f[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < S; ++j) {
            if (!check(i, j))
                continue;
            for (int k = 0; k < S; ++k) {
                if (k & j)
                    continue;
                (f[i][j] += f[i - 1][k]) %= mod;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < S; ++i)
        (ans += f[n][i]) %= mod;
    printf("%lld\n", ans);
    return 0;
}