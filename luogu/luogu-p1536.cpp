/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-17 00:40:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-19 00:37:16
 */
#include <iostream>
#include <cstdio>

const int maxn = 1005;
int fa[maxn];

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

void _union(int x, int y) {
    int fax = find(x);
    int fay = find(y);
    fa[fax] = fay;
}

int main() {
    for (;;) {
        int n, m;
        std :: scanf("%d", &n);

        if (!n) {
            return 0;
        }

        std :: scanf("%d", &m);
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        while (m--) {
            int x, y;
            std :: scanf("%d%d", &x, &y);
            _union(x, y);
        }

        int ans = -1;
        for (int i = 1; i <= n; ++i)
            if (fa[i] == i)
                ++ans;
        std :: printf("%d\n", ans);
    }
}