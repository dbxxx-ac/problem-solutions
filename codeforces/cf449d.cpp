/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-18 19:02:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-18 19:26:04
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

const int mod = (int)1e9 + 7;
const int lg = 20;
int g[(1 << lg) + 5], pw2[(1 << lg) + 5];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        ++g[read()];
    pw2[0] = 1;
    for (int i = 1; i < (1 << lg); ++i)
        pw2[i] = pw2[i - 1] * 2 % mod;
    for (int j = 0; j < lg; ++j) {
        for (int i = (1 << lg) - 1; ~i; --i) {
            if ((i & (1 << j)) == 0) {
                int lst = i ^ (1 << j);
                (g[i] += g[lst]) %= mod;
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < (1 << lg); ++x) {
        (ans += (pw2[g[x]] - 1) * (__builtin_parityll(x) ? -1 : 1) + mod) %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}