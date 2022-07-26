/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-02 22:04:01 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-02 22:38:27
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 15005;
struct road {
    long long l, r;
    const bool operator < (const road& b) {
        return this -> r - this -> l > b.r - b.l;
    }
}r[maxn];

long long a[maxn];

int main() {
    int n, m;
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%lld", &a[i]);
    
    for (int i = 1; i <= n - 1; ++i) {
        r[i].l = a[i];
        r[i].r = a[i + 1];
    }

    std :: sort(r + 1, r + n);
    
    long long ans = a[n] - a[1];
    
    for (int i = 1; i <= m - 1; ++i)
        ans -= r[i].r - r[i].l;
    
    std :: printf("%lld\n", ans + m);
    return 0;
}