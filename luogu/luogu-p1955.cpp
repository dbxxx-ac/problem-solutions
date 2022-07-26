/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-19 18:52:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-20 01:57:10
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1000005;
int disc[maxn * 2], fa[maxn];

struct restrain {
    int i, j, e;
}a[maxn];

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
    return ;
}

bool check(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int t;
    std :: scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(disc, 0, sizeof(disc));

        int n, discidx = 0;
        bool flag = true;
        std :: scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            std :: scanf("%d%d%d", &a[i].i, &a[i].j, &a[i].e);
            disc[++discidx] = a[i].i;
            disc[++discidx] = a[i].j;
        }

        std :: sort(disc + 1, disc + 1 + discidx);
        disc[0] = std :: unique(disc + 1, disc + 1 + discidx) - disc - 1;
        for (int i = 1; i <= n; ++i) {
            a[i].i = std :: lower_bound(disc + 1, disc + 1 + disc[0], a[i].i) - disc - 1 + 1;
            a[i].j = std :: lower_bound(disc + 1, disc + 1 + disc[0], a[i].j) - disc - 1 + 1;
        }

        for (int i = 1; i <= disc[0]; ++i)
            fa[i] = i;
        
        for (int i = 1; i <= n; ++i)
            if (a[i].e)
                unite(a[i].i, a[i].j);
        
        for (int i = 1; i <= n; ++i) {
            if (!a[i].e) {
                if (check(a[i].i, a[i].j)) {
                    std :: printf("NO\n");
                    flag = false;
                    break;
                }
            }
        }

        if (flag) std :: printf("YES\n");
    }
}