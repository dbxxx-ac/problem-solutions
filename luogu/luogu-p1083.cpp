/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 11:19:38 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 11:30:38
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
const int maxm = (int)1e6 + 5;

int n, m;

int a[maxn];
int ls[maxm], rs[maxm], vs[maxm];
int d[maxn];

inline bool check(int x) {
    if (x > m)
        return false;
    std :: memset(d, 0, sizeof(d));
    for (int i = 1; i <= x; ++i) {
        int l = ls[i], r = rs[i], v = vs[i];
        d[l] += v;
        d[r + 1] -= v;
    }
    std :: partial_sum(d + 1, d + 1 + n, d + 1);
    for (int i = 1; i <= n; ++i)
        if (d[i] > a[i])
            return false;
    return true;
}

signed main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= m; ++i) {
        vs[i] = read();
        ls[i] = read();
        rs[i] = read();
    }

    int ans = 0;
    for (int i = (1 << 20); i; i >>= 1)
        if (check(ans + i))
            ans += i;
    if (ans == m)
        puts("0");
    else
        printf("-1\n%lld\n", ans + 1);
    return 0;
}