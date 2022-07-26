/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-30 22:15:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-30 22:58:22
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 100005;

struct G {
    int s, p;
    const bool operator < (const G& b) {
        return this -> p < b.p;
    }
}a[maxn];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, b, ans = 1008610086;
    std :: scanf("%d %d", &n, &b);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d %d", &a[i].s, &a[i].p);
    
    std :: sort(a + 1, a + 1 + n);

    int pos;
    for (pos = 1; pos <= n && a[pos].p < b; ++pos);
    
    int l = pos - 1, r = pos, d = a[r].p - a[l].p;
    while (l >= 1 && r <= n) {
        if (a[l].s >= d && a[r].s >= d) {
            puts("0");
            return 0;
        } else if (a[r].s < d) {
            ++r;
            d += a[r].p - a[r - 1].p;
        } else if (a[l].s < d) {
            ans = min(ans, d - a[l].s);
            --l;
            d += a[l + 1].p - a[l].p;
        }
    }

    l = pos - 1, r = pos, d = a[r].p - a[l].p;
    while (l >= 1 && r <= n) {
        if (a[l].s >= d && a[r].s >= d) {
            puts("0");
            return 0;
        } else if (a[l].s < d) {
            --l;
            d += a[l + 1].p - a[l].p;
        } else if (a[r].s < d) {
            ans = min(ans, d - a[r].s);
            ++r;
            d += a[r].p - a[r - 1].p;
        }
    }

    if (ans == 1008610086) ans = -1;
    std :: printf("%d\n", ans);
    return 0;
}