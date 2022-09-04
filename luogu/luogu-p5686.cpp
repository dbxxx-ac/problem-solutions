/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 10:49:09 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 11:09:34
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

const int maxn = (int)5e5 + 5;
const int mod = (int)1e9 + 7;

int c[maxn], d[maxn], e[maxn], f[maxn], g[maxn];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        c[i] = (c[i - 1] + read()) % mod;
    
    for (int i = 1; i <= n; ++i)
        d[i] = (d[i - 1] + read()) % mod;

    for (int i = n; i >= 1; --i) {
        e[i] = (e[i + 1] + c[i]) % mod;
        f[i] = (f[i + 1] + d[i]) % mod;
        g[i] = (g[i + 1] + c[i] * d[i] % mod) % mod;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        (ans += g[i] + mod) %= mod;
        (ans += (n - i + 1) * c[i - 1] % mod * d[i - 1] % mod) %= mod;
        ans -= d[i - 1] * e[i] % mod;
        ans = (ans + mod) % mod;
        ans -= c[i - 1] * f[i] % mod;
        ans = (ans + mod) % mod;
    }

    printf("%lld\n", ans);
    return 0;
}