/*
 * @Author: crab-in-the-northeast
 * @Date: 2022-09-19 19:21:25
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-19 23:14:59
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
    if (flag)
        return x;
    return ~(x - 1);
}

const int maxn = 2005;
const int maxm = maxn * maxn;

struct edge {
    int u, v, w;
} e[maxm];
int ecnt = 0;

int a[maxn];
int fa[maxn];

inline int get(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

inline void uni(int x, int y) {
    x = get(x);
    y = get(y);
    fa[x] = y;
}

signed main() {
    int n = read();

    for (int i = 1; i <= n; ++i) a[i] = read();

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            e[++ecnt] = (edge){ i, j, 1LL * a[i] ^ a[j] };
        }
    }

    std ::sort(e + 1, e + 1 + ecnt, [](edge a, edge b) { return a.w > b.w; });

    std ::iota(fa + 1, fa + 1 + n, 1LL);
    int ans = 0;
    for (int i = 1, con = 0; i <= ecnt; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (get(u) == get(v))
            continue;
        ans += w;
        ++con;
        uni(u, v);
        if (con == n - 1)
            break;
    }

    printf("%lld\n", ans);
    return 0;
}

/*
3 6 9 10


*/