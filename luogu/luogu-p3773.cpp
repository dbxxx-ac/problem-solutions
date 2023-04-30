/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-20 01:31:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-20 01:37:39
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
const int maxa = 250005;
const int mod = (int)1e9 + 7;

int f[maxa];

signed main() {
    int n = read(), ans = 0;

    for (int i = 1; i <= n; ++i) {
        int x = read();
        for (int j = (x & (x - 1)); j; j = (x & (j - 1)))
            (f[j] += f[x] + 1) %= mod;
        (ans += f[x]) %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}