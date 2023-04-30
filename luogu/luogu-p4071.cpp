/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-20 00:13:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-20 00:23:16
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

const int maxn = (int)1e6 + 5;
const int mod = (int)1e9 + 7;

inline int pw(int a, int b = mod - 2) {
    int ans = 1;
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1)
            (ans *= a) %= mod;
    return ans;
}

int d[maxn], fac[maxn], iac[maxn];

inline void pre(int n) {
    fac[0] = iac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        iac[i] = pw(fac[i]);
    }

    d[0] = 1;
    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= n; ++i)
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
}

signed main() {
    pre(maxn - 5);
    int T = read();
    while (T--) {
        int n = read(), m = read();
        printf("%lld\n", fac[n] * iac[m] % mod * iac[n - m] % mod * d[n - m] % mod);
    }

    return 0;
}