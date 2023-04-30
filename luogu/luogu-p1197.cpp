/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-20 16:28:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-20 18:35:03
 */
#include <bits/stdc++.h>
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

const int maxn = (int)4e5 + 5;
const int maxm = (int)2e5 + 5;

int fa[maxn], a[maxn];
struct edge {
    int u, v, t;
} e[maxm];

inline int get(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

int ans[maxn];
// ans[i]：加了后 i 个点后的答案 = 删了前 k - i 个点后的答案
// 依次输出删了 0 ~ k 个点后的答案 -> 输出 ans[k -> 0]
int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        e[i].u = read() + 1;
        e[i].v = read() + 1;
    }
    int k = read();
    for (int i = 1; i <= k; ++i)
        a[read() + 1] = k + 1 - i;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v;
        e[i].t = std :: max(a[u], a[v]);
    }

    std :: sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.t < b.t;
    });

    int bl = ans[0] = n - k;
    std :: iota(fa + 1, fa + 1 + n, 1);
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, t = e[i].t;
        bl += t - e[i - 1].t;
        if (unite(u, v))
            --bl;
        ans[t] = bl;
    }

    for (int i = 1; i <= k; ++i)
        if (ans[i] == 0)
            ans[i] = ans[i - 1] + 1;
    for (int i = k; ~i; --i)
        printf("%d\n", ans[i]);
    return 0;
}