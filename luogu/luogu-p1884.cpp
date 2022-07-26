/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-31 10:57:53 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-10-31 10:57:53 
 */
#include <iostream>
#include <cstdio>

const int maxn = 1005;
inline long long max(long long a, long long b) {
    return a > b ? a : b;   
}
inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

struct rectangle {
    long long x1, y1;
    long long x2, y2;
}a[maxn];

int cnt = 0;

void cut(int id, int x1, int y1, int x2, int y2) {
    long long k1, k2, k3, k4;
    k1 = max(a[id].x1, x1);
    k2 = min(a[id].x2, x2);
    k3 = min(a[id].y1, y1);
    k4 = max(a[id].y2, y2);
    if (a[id].x1 < k1) a[++cnt] = (rectangle){a[id].x1, a[id].y1, k1, a[id].y2};
    if (a[id].x2 > k2) a[++cnt] = (rectangle){k2, a[id].y1, a[id].x2, a[id].y2};
    if (a[id].y1 > k3) a[++cnt] = (rectangle){k1, a[id].y1, k2, k3};
    if (a[id].y2 < k4) a[++cnt] = (rectangle){k1, k4, k2, a[id].y2};
}

int main() {
    int n;
    std :: scanf("%d", &n);
    
    long long x1, y1, x2, y2;
    std :: scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    a[++cnt] = (rectangle){x1, y1, x2, y2};
    for (int i = 2; i <= n; ++i) {
        std :: scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        for (int j = 1; j <= cnt; ++j) {
            if (a[j].x1 < x2 && a[j].x2 > x1 && a[j].y1 > y2 && a[j].y2 < y1) {
                cut(j, x1, y1, x2, y2);
                a[j--] = a[cnt--];
            }
        }
        a[++cnt] = (rectangle){x1, y1, x2, y2};
    }

    long long ans = 0;
    for (int i = 1; i <= cnt; ++i)
        ans += (a[i].x2 - a[i].x1) * (a[i].y1 - a[i].y2);
    std :: printf("%lld\n", ans);
    return 0;
}