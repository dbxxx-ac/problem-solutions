/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-14 15:50:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-14 16:32:02
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

const int maxn = (int)1e5 + 5;

int a[maxn], f[maxn], g[maxn];
int nxt[maxn];

inline int abs(int x) {
    return x > 0 ? x : -x;
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        f[i] = f[i - 1] + a[i];
    }

    int p = n + 1;
    
    for (int i = n; i >= 1; --i) {
        g[i] = g[i + 1] + a[i];
        if (a[i] < 0) {
            g[i] = g[i + 1] - a[i];
            nxt[i] = p;
            p = i;
        }
    }

    int ans = f[n];

    if (p != n + 1) {
        for (int i = p; i <= n; i = nxt[i]) {
            if (nxt[i] == n + 1)
                break;
            ans = max(ans, f[i] - (f[nxt[i] - 1] - f[i]) + g[nxt[i]]);
        }
    }

    printf("%lld\n", ans);
    return 0;
}