/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-31 05:16:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-31 05:23:44
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

int r[maxn], w[maxn], g[maxn];

signed main() {
    int n = read(), m = read();

    std :: mt19937 rng(time(0));
    
    for (int u = 1; u <= n; ++u)
        w[u] = rng();
    
    int tar = std :: accumulate(w + 1, w + n + 1, 0LL);
    // 这是求和函数，注意 0 后面要加 LL （否则会爆）

    int now = 0;
    while (m--) {
        int u = read(), v = read();
        r[v] += w[u];
        g[v] = r[v];
        now += w[u];
    }

    int q = read();
    while (q--) {
        int t = read();
        if (t == 1) {
            int u = read(), v = read();
            r[v] -= w[u];
            now -= w[u];
        } else if (t == 2) {
            int v = read();
            now -= r[v];
            r[v] = 0;
        } else if (t == 3) {
            int u = read(), v = read();
            r[v] += w[u];
            now += w[u];
        } else if (t == 4) {
            int v = read();
            now += g[v] - r[v];
            r[v] = g[v];
        }

        puts(now == tar ? "YES" : "NO");
    }

    return 0;
}