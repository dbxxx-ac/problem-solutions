/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-19 18:31:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-19 21:06:08
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
const int maxn = 100005;

int fa[maxn << 1], siz[maxn << 1], sum[maxn << 1];

inline int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline bool uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (siz[x] > siz[y])
        std :: swap(x, y);
    fa[x] = y;
    sum[y] += sum[x];
    siz[y] += siz[x];
    return true;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        std :: iota(fa + 1, fa + 1 + n, n + 1);
        std :: iota(fa + 1 + n, fa + 1 + n * 2, n + 1);
        std :: fill(siz + 1 + n, siz + 1 + n * 2, 1);
        std :: iota(sum + 1 + n, sum + 1 + n * 2, 1);
        
        while (m--) {
            int op = read();
            if (op == 1) {
                int x = read(), y = read();
                uni(x, y);
            } else if (op == 2) {
                int x = read(), y = read();
                y = find(y);
                ++siz[y];
                --siz[find(x)];
                sum[y] += x;
                sum[find(x)] -= x;
                fa[x] = y;
            } else {
                int x = read();
                x = find(x);
                printf("%d %d\n", siz[x], sum[x]);
            }
        }
    }

    return 0;
}