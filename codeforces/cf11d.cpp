/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-19 19:45:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-19 20:59:00
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

const int maxn = 20;
int f[1LL << maxn][maxn];
bool a[maxn][maxn];

signed main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read() - 1, v = read() - 1;
        a[u][v] = a[v][u] = true;
    }

    int N = (1LL << n);
    for (int u = 0; u < n; ++u)
        f[1LL << u][u] = 1;
    
    int ans = 0;

    for (int S = 0; S < N; ++S) {
        int s = (S & (-S));
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) if (a[u][v]) {
                if ((1LL << v) < s)
                    continue;
                if (S & (1LL << v)) {
                    if ((1LL << v) == s)
                        ans += f[S][u];
                } else
                    f[S | (1LL << v)][v] += f[S][u];
            }
        }
    }

    printf("%lld\n", (ans - m) >> 1LL);
    return 0;
}
