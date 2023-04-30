/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-03 21:21:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-03 21:27:55
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

const int mod = 998244353;
const int inv = 828542813;
const int maxn = (int)2e5 + 5;

int f[maxn];

signed main() {
    int n = read(), p = read(), q = 100 - p;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = ((f[i - 1] * q % mod + f[i - 2] * p % mod) % mod * inv + 1) % mod;
    printf("%lld\n", f[n]);
    return 0;
}